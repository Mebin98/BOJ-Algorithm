#include <stdio.h>

int main()
{
	//number of antenna that the witness claimed to have senn on the alien
	//number of eyes seen on the alien
	int antenna, eyes;

	scanf("%d", &antenna);
	scanf("%d", &eyes);

	//case for troy
	if (antenna >= 3)
	{
		if (eyes <= 4) printf("TroyMartian\n");
	}
	//case for Vlad
	if (antenna <= 6)
	{
		if (eyes >= 2) printf("VladSaturnian\n");
	}
	//case for Grae
	if (antenna <= 2)
	{
		if (eyes <= 3) printf("GraemeMercurian\n");
	}

	return 0;
}