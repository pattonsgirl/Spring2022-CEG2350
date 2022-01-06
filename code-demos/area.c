#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define PI 3.14159

double circle_area(double);
double ring_area(double, double);

int main(void) {
  double rad_outer = 8.5;
  double rad_inner = 5.5;
  //area_ring = 56;
  double area_outer;
  double area_ring;
  char selection;
  printf("Value of PI is: %lf", PI);
  printf("2 * PI = %lf", 2 * PI);
  //switch statement that asks user if they want a circle or a ring (for area) 
  printf("c for circle area, r for ring area: ");
  scanf("%c", &selection);
  while(getchar()!='\n');
  switch (selection){
    case 'c':
      area_outer = circle_area(rad_outer);
      printf("The circle area is %lf\n", area_outer);
      break;
    case 'r':
      area_ring = ring_area(rad_outer, rad_inner);
      printf("The area of the ring is %lf\n", area_ring);
      break;
    default:
      printf("NOT AN OPTION\n");
      break;
  }

  return 0; 
}

//create a function that calculates area of a circle
double circle_area (double radius){
  double area = PI * radius * radius;
  printf("The area is %lf\n", area);
  return area;
}

double ring_area (double outer_radius, double inner_radius){
  double outer_area;
  double inner_area;
  outer_area = circle_area(outer_radius);
  inner_area = circle_area(inner_radius);
  double ring_area;
  ring_area = outer_area - inner_area;
  return ring_area;
}
