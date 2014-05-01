/*
 * server.h
 *
 *  Created on: 19 марта 2014 г.
 *      Author: volodja
 */





#ifndef SERVER_H_
#define SERVER_H_



namespace server {


/**
 *  service interface
 */
class IService {
public:
                    IService() {};
    virtual        ~IService() {};

    virtual void    start() = 0;
    virtual void    stop() = 0;
};


}


#endif /* SERVER_H_ */
