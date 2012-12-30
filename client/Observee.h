/* 
 * File:   Observee.h
 * Author: cranberry
 *
 * Created on 30 décembre 2012, 13:52
 */

#ifndef OBSERVEE_H
#define	OBSERVEE_H

#include <vector>
#include <algorithm>
#include "Observer.h"
class Observer;
//-----------------------------------------------------
// Observee Class									
//-----------------------------------------------------
class Observee
{
public:
	
	virtual ~Observee();		//destructor

	bool AddObserver(Observer* observer);
	bool RemoveObserver(Observer* observer);
	bool NotifyObservers();
protected:
	//constructor is protected because this class is abstract, it’s only meant to be inherited!
	Observee();
private: 
	std::vector<Observer*> m_ObserverVec;
	// -------------------------
	// Disabling default copy constructor and default 
	// assignment operator.
	// -------------------------
	Observee(const Observee& yRef);									
	//Observee& operator=(const Observee& yRef);	
};



#endif	/* OBSERVEE_H */

