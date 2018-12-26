#include <string>
using namespace std;
class NvGui2{
private:
	std::string name;
	NvGui2(std::string name);
public:
	static NvGui2 *getObject();
	void show();
	void setName(string name);
};
