class IGarageItem {
public:
	virtual void move() = 0;
	int getCount() { return this->count; }
	~IGarageItem() {}

protected:
	int count;
};