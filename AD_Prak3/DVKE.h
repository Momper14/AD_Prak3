#pragma once
class DVKE{
private:
	DVKE * v;
	DVKE* n;
public:
	DVKE(DVKE*, DVKE*);
	DVKE();

	DVKE* getV() const;
	void setV(DVKE*);
	DVKE* getN() const;
	void setN(DVKE*);

	~DVKE();
};