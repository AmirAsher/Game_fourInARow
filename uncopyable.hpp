#ifndef __UNCOPYABLE_H__
#define __UNCOPYABLE_H__


namespace fourInARow_Game{

class UnCopyable{
	
public:
	UnCopyable(){}
	
private: 
	UnCopyable(const UnCopyable& _unCopy);
	UnCopyable& operator=(const UnCopyable& _unCopy);
};


} //namespace fourInARow_Game

#endif //__UNCOPYABLE_H__



