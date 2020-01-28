class N {
	N();
	int n;
	char *str;
};

N::N(void) {

}

void N::setAnnotation(char *src) {
	size_t len = strlen(src);
	memcpy(this->str, src, len);
}

int main(int ac, char **av)
{
	if (ac != 1)
		exit(1);

	N n1 = new N(5);
	N n2 = new N(6);

	n1.setAnnotation(av[1]);

}
