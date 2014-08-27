/* Copyright 2003-2005 Joaqu�n M L�pez Mu�oz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See Boost website at http://www.boost.org/
 */

#ifndef SC_BOOST_DETAIL_ALLOCATOR_UTILITIES_HPP
#define SC_BOOST_DETAIL_ALLOCATOR_UTILITIES_HPP

#include <sysc/packages/boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <sysc/packages/boost/detail/workaround.hpp>
#include <sysc/packages/boost/mpl/aux_/msvc_never_true.hpp>
#include <sysc/packages/boost/mpl/eval_if.hpp>
#include <sysc/packages/boost/type_traits/is_same.hpp>
#include <cstddef>
#include <memory>
#include <new>

namespace sc_boost{

namespace sc_detail{

/* Allocator adaption layer. Some stdlibs provide allocators without rebind
 * and template ctors. These facilities are simulated with the external
 * template class rebind_to and the aid of partial_std_allocator_wrapper.
 */

namespace sc_allocator{

/* partial_std_allocator_wrapper inherits the functionality of a std
 * allocator while providing a templatized ctor.
 */

template<typename Type>
class partial_std_allocator_wrapper:public std::allocator<Type>
{
public:
  partial_std_allocator_wrapper(){};

  template<typename Other>
  partial_std_allocator_wrapper(const partial_std_allocator_wrapper<Other>&){}

  partial_std_allocator_wrapper(const std::allocator<Type>& x):
    std::allocator<Type>(x)
  {
  };

#if defined(SC_BOOST_DINKUMWARE_STDLIB)
  /* Dinkumware guys didn't provide a means to call allocate() without
   * supplying a hint, in disagreement with the standard.
   */

  Type* allocate(std::size_t n,const void* hint=0)
  {
    std::allocator<Type>& a=*this;
    return a.allocate(n,hint);
  }
#endif

};

/* Detects whether a given allocator belongs to a defective stdlib not
 * having the required member templates.
 * Note that it does not suffice to check the Boost.Config stdlib
 * macros, as the user might have passed a custom, compliant allocator.
 * The checks also considers partial_std_allocator_wrapper to be
 * a standard defective allocator.
 */

#if defined(SC_BOOST_NO_STD_ALLOCATOR)&&\
  (defined(SC_BOOST_HAS_PARTIAL_STD_ALLOCATOR)||defined(SC_BOOST_DINKUMWARE_STDLIB))

template<typename Allocator>
struct is_partial_std_allocator
{
  SC_BOOST_STATIC_CONSTANT(bool,
    value=
      (is_same<
        std::allocator<SC_BOOST_DEDUCED_TYPENAME Allocator::value_type>,
        Allocator
      >::value)||
      (is_same<
        partial_std_allocator_wrapper<
          SC_BOOST_DEDUCED_TYPENAME Allocator::value_type>,
        Allocator
      >::value));
};

#else

template<typename Allocator>
struct is_partial_std_allocator
{
  SC_BOOST_STATIC_CONSTANT(bool,value=false);
};

#endif

/* rebind operations for defective std allocators */

template<typename Allocator,typename Type>
struct partial_std_allocator_rebind_to
{
  typedef partial_std_allocator_wrapper<Type> type;
};

/* rebind operation in all other cases */

#if SC_BOOST_WORKAROUND(SC_BOOST_MSVC,<1300)
/* Workaround for a problem in MSVC with dependent template typedefs
 * when doing rebinding of allocators.
 * Modeled after <sysc/packages/boost/mpl/aux_/msvc_dtw.hpp> (thanks, Aleksey!)
 */

template<typename Allocator>
struct rebinder
{
  template<bool> struct fake_allocator:Allocator{};
  template<> struct fake_allocator<true>
  {
    template<typename Type> struct rebind{};
  };

  template<typename Type>
  struct result:
    fake_allocator<mpl::aux::msvc_never_true<Allocator>::value>::
      template rebind<Type>
  {
  };
};
#else
template<typename Allocator>
struct rebinder
{
  template<typename Type>
  struct result
  {
      typedef typename Allocator::SC_BOOST_NESTED_TEMPLATE 
          rebind<Type>::other other;
  };
};
#endif

template<typename Allocator,typename Type>
struct compliant_allocator_rebind_to
{
  typedef typename rebinder<Allocator>::
      SC_BOOST_NESTED_TEMPLATE result<Type>::other type;
};

/* rebind front-end */

template<typename Allocator,typename Type>
struct rebind_to:
  mpl::eval_if_c<
    is_partial_std_allocator<Allocator>::value,
    partial_std_allocator_rebind_to<Allocator,Type>,
    compliant_allocator_rebind_to<Allocator,Type>
  >
{
};

/* allocator-independent versions of construct and destroy */

template<typename Type>
void construct(void* p,const Type& t)
{
  new (p) Type(t);
}

template<typename Type>
void destroy(const Type* p)
{
  p->~Type();
}

} /* namespace sc_boost::sc_detail::sc_allocator */

} /* namespace sc_boost::sc_detail */

} /* namespace sc_boost */

#endif
