

class Transport
{
public:
	Transport(void);
	// comment action
	virtual void Run()=0;
private:
	// base attributes
	float length;
	float weight;
	float speed;
};

// (b)  既是基类又是派生类的有： 飞机和汽车

// (C)  运载工具的派生类有： 飞机，汽车，电动式，喷气式 
