#include <cstring>
#include <cstdlib>
#include <cstdio>

class N {
	public:
		N(int n);
		void setAnnotation(char *src);
		int n;
		char *str;
};

N::N(int n) {
	this->n = n;
}

void N::setAnnotation(char *src) {
	std::size_t len = std::strlen(src);
	memcpy(this->str, src, len);
}

int main(int ac, char **av)
{
	if (ac != 2)
		std::exit(1);
	N n1 = N(5);
	N n2 = N(6);
    n1.setAnnotation(av[1]);
	return (0);
}
