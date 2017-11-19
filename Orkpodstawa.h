#pragma once
class Orkpodstawa
{
public:

	virtual atakuj() = 0;
	virtual	 void  rysujOrka()=0;

protected:
	string nazwa;
	int zycie;

	Orkpodstawa();
	virtual ~Orkpodstawa();
};

