/* 
 * File:   Observer.h
 * Author: cranberry
 *
 * Created on 30 décembre 2012, 13:51
 */

#ifndef OBSERVER_H
#define	OBSERVER_H


#include <vector>
using namespace std;
#include "Observee.h"
class Observee;
//-----------------------------------------------------
// Observer Class			
//-----------------------------------------------------
class Observer
{
public:
	virtual ~Observer();		// Destructor
	virtual void Notify(Observee* observee){};
protected:
//constructor is protected because this class is abstract, it’s only meant to be inherited!
	Observer();
private: 
	// -------------------------
	// Disabling default copy constructor and default 
	// assignment operator.
	// -------------------------
	Observer(const Observer& yRef);	
	Observer& operator=(const Observer& yRef);	
};



#endif	/* OBSERVER_H */

