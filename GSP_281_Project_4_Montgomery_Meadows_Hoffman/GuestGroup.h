#ifndef GUESTGROUP_H
#define GUESTGROUP_H

class GuestGroup
{
public:
	GuestGroup(const int size):M_Size(size){};
	~GuestGroup(void){};
	inline int GetSize(void)const{return M_Size;}
private:
	const int M_Size;
};

#endif