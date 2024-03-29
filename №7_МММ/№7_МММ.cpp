// №7_МММ.cpp : Defines the entry point for the console application.
//
//Runge Kutta
#include "stdafx.h"
#include <iostream>
#include<vector>
#include<math.h>
#include <tuple>
#include <fstream>

using namespace std;

double V(double y) {
	double f = y;
	return f;
}
double U(double x, double y, double z) {
	double f = -8.0*z-4*y+x*exp(-x);
	return f;
}

tuple<double, double, double, double> rk4funct1(double z, double d, double q) {
	double k1 = 0.0, k2 = 0.0, k3 = 0.0, k4 = 0.0;
	
	k1 = V(z);
	k2 = V(z + q*d*0.5);
	k3 = V(z + q*d*0.5);
	k4 = V(z + q*d);
	return make_tuple(k1, k2, k3, k4);
}

tuple<double, double, double, double> rk4funct2(double x, double y, double z, double d, double  k) {
	double q0 = 0.0, q1 = 0.0, q2 = 0.0, q3 = 0.0;
	q0 = U(x, y, z);
	q1 = U(x + 0.5*d, y + 0.5*k, z);
	q2 = U(x + 0.5*d, y + 0.5*k, z);
	q3 = U(x + d, y + k, z);
	return std::make_tuple(q0, q1, q2, q3);
}

int main() {

	double y0{ 1.0 }, z{ 0.0 }; //initial y value
	double t0{ 0.0 }; //initial time value
	double d{ 0.01 }; //step size
	double n{ 2/ d }; //number of iterations
	vector<double> yvector(1, y0);
	//yvector.resize(0.0);
	vector<double> tvector(1, t0);
	//tvector.resize(0.0);
	vector<double> zvector(1, z);
	//zvector.resize(0.0);
	

	double k0=0.0, k1 = 0.0, k2 = 0.0, k3 = 0.0, q3 = 0.0, q0 = 0.0, q1 = 0.0, q2 = 0.0;
	ofstream f("ans1.dat");
	//cout << "Please input variables according to the following order: step size, y0, t0, n(# of iterations)\n";
	
	//cin >> d >> y0 >> t0 >> n;
	//n = 2.0 / d;

	//yvector.push_back(y0);
	//tvector.push_back(t0);
	//zvector.push_back(z);
	cout << zvector[0] << "|" << yvector[0] << "|" << tvector[0] << endl;
	f << " " << tvector[0] << " " << yvector[0] << " " << zvector[0] << endl;
	for (int i{ 0 }; i<n; i++) {
		k0 = V(zvector[i]);				q0 = U(tvector[i], yvector[i], zvector[i]);
		k1 = V(zvector[i] + q0*d*0.5);	q1 = U(tvector[i] + 0.5*d, yvector[i] + 0.5*d*k0, zvector[i] + 0.5*d*q0);
		k2 = V(zvector[i] + q1*d*0.5);	q2 = U(tvector[i] + 0.5*d, yvector[i] + 0.5*d*k1, zvector[i] + 0.5*d*q1);
		k3 = V(zvector[i] + q2*d);		q3 = U(tvector[i] + d, yvector[i] + d*k2, zvector[i] + d*q2);
		cout << i << ":	" << zvector[i] << "|" << yvector[i] << "|" << tvector[i] << "		";
		/*auto ret1 = rk4funct1(zvector[i], d, q1);
		auto ret2 = rk4funct2(tvector[i], yvector[i], zvector[i], d, k1);
		k1 = get<0>(ret1);
		q1 = get<0>(ret2);
		auto ret1 = rk4funct1(zvector[i], d, q2);
		auto ret2 = rk4funct2(tvector[i], yvector[i], zvector[i], d, k2);
		k2 = get<1>(ret1);
		q2 = get<1>(ret2);
		auto ret1 = rk4funct1(zvector[i], d, q3);
		auto ret2 = rk4funct2(tvector[i], yvector[i], zvector[i], d, k3);
		k3 = get<2>(ret1);
		q2 = get<2>(ret2);
		auto ret1 = rk4funct1(zvector[i], d, q4);
		auto ret2 = rk4funct2(tvector[i], yvector[i], zvector[i], d, k4);
		k4 = get<3>(ret1);
		q4 = get<3>(ret2);*/

		zvector.push_back(zvector[i] + d / 6.0*(q0 + 2.0*q1 + 2.0*q1 + q2)) ;
		yvector.push_back(yvector[i] + (d / 6)*(k0 + 2 * k1 + 2 * k2 + k3));
		tvector.push_back(tvector[i] + d); //same here.

		cout <<zvector[i + 1] << "|" << yvector[i + 1] << "|" << tvector[i + 1] << endl;
		f << " " << tvector[i + 1] << " " << yvector[i + 1] << " " << zvector[i + 1] << endl;
	}
	f.close();
	system("pause");
	return 0;
}