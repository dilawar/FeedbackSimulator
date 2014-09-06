/*
 * ==============================================================================
 *
 *       Filename:  channel.h
 *
 *    Description:  A stochastic channel.
 *
 *        Version:  1.0
 *        Created:  Saturday 06 September 2014 03:25:39  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dilawar Singh (), dilawars@ncbs.res.in
 *   Organization:  
 *
 * ==============================================================================
 */


#ifndef  CHANNEL_INC
#define  CHANNEL_INC

/**
 * @brief Channel class.
 *
 */
class Channel
{
public:
    Channel();
    ~Channel();

    void setId(unsigned int id_);
    unsigned int getId();

public:
    unsigned int id_;

private:
    /* data */
};

#endif   /* ----- #ifndef CHANNEL_INC  ----- */
