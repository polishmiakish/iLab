#include <iostream>

template <typename T>

class CDot{
	
	public :
		T x;
		T y;
		CDot(){
			std::cout << "Constructor works\n";
		}
		~CDot(){
			std::cout << "Destructor works\n";
		};
};

int main(){
	double a, b;
	CDot <double> d[4], f;
	int i;
	for (i = 0; i < 4; i++){
		std::cin >> a >> b;
		d[i].x = a;
		d[i].y = b;
	}
	double t;
	std::cin >> t;
	if (t >= 0){
		if (t <= 1){
			f.x = d[0].x + t * (d[1].x - d[0].x);
			f.y = d[0].y + t * (d[1].y - d[0].y);
		} else if (t <= 2){
			f.x = d[1].x + (t - 1) * (d[2].x - d[1].x);
			f.y = d[1].y + (t - 1) * (d[2].y - d[1].y);
		} else if (t <= 3){
			f.x = d[2].x + (t - 2) * (d[3].x - d[2].x);
			f.y = d[2].y + (t - 2) * (d[3].y - d[2].y);
		} else std::cout << "Wrong parameter\n";
	} else std::cout << "Wrong parameter\n";
	if ((t >= 0) && (t <=3))
		std::cout << f.x << " " << f.y << "\n";
	return 0;
}
