#include <stdio.h>
main() {int hours; long minute; long seconds; float days, weeks, years;
	printf("HOURS?: "); scanf("%d", &hours);
	minute = hours * 60; seconds = minute * 60; days = hours / 24; weeks = days / 7; years = days / 365;
	printf("\nYEARS~~ %f\n", years);
	printf("WEEKS~~ %f\n", weeks);
	printf("DAYS~~ %f\n", days);
	printf("HOURS: %d\n", hours);
	printf("MINUTES: %ld\n", minute);
	printf("SECONDS: %ld", seconds);
}
