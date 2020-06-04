#ifndef CUSTOMER_H_
#define CUSTOMER_H_
class Customer {
private:
	long arrive; // момент появления клиента
	int processtime; // время обслуживания клиента
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
inline void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1; 
	arrive = when;
}
#endif // !CUSTOMER_H_
