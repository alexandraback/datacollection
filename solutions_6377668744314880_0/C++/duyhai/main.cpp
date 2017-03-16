#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <set>
#include <numeric>
#include <map>
#define M_PI           3.14159265358979323846
using namespace std;

class Vector3D {
	// The two coordinates
	long long _x, _y, _z;

public:
	// Constructors
	Vector3D() {
		_x = 0;
		_y = 0;
		_z = 0;
	}

	Vector3D(long long x, long long y, long long z) {
		_x = x;
		_y = y;
		_z = z;
	}

	Vector3D(Vector3D &v) {
		_x = v.GetX();
		_y = v.GetY();
		_z = v.GetZ();
	}

	// Getters and setters for the coordinates
	void SetVector(Vector3D v) {
		_x = v.GetX();
		_y = v.GetY();
		_z = v.GetZ();
	}

	void SetVector(long long x, long long y, long long z) {
		_x = x;
		_y = y;
		_z = z;
	}

	long long GetX() {
		return _x;
	}

	void SetX(long long x) {
		_x = x;
	}

	long long GetY() {
		return _y;
	}

	void SetY(long long y) {
		_y = y;
	}

	long long GetZ() {
		return _z;
	}

	void SetZ(long long z) {
		_z = z;
	}

	// Set a vector with polar coordinates
	void SetVectorPolar(long long len, long long thetaRad, long long phiRad) {
		_x = len * sin(thetaRad) * cos(phiRad);
		_y = len * sin(thetaRad) * sin(phiRad);
		_z = len * cos(thetaRad);
	}

	// Get vector length
	long long GetLength() {
		return sqrt(_x * _x + _y * _y + _z * _z);
	}

	// Set a vector's length
	void SetLength(long long len) {
		SetVector(this->Normalize().ScalarProduct(len));
	}

	// Clone a Vector
	Vector3D Clone() {
		return Vector3D(*this);
	}

	// Add another vector
	Vector3D Add(Vector3D &v) {
		return Vector3D(_x + v.GetX(), _y + v.GetY(), _z + v.GetZ());
	}

	// Substract another vector
	Vector3D Minus(Vector3D &v) {
		return Vector3D(_x - v.GetX(), _y - v.GetY(), _z - v.GetZ());
	}

	// Multiply a vector with a number
	Vector3D ScalarProduct(long long multiplier) {
		return Vector3D(_x * multiplier, _y * multiplier, _z
			* multiplier);
	}

	// Set a vector's length to 1
	Vector3D Normalize() {
		if (this->GetLength() < 0.001f)
			return Vector3D();
		return this->ScalarProduct(1 / this->GetLength());
	}

	// Dot product of two vectors
	long long DotProduct(Vector3D v) {
		return _x * v.GetX() + _y * v.GetY() + _z * v.GetZ();
	}

	// Warning: Points in opposite direction, because of inverted Y axis!
	// Vector product of two vectors
	Vector3D VectorProduct(Vector3D &v) {
		return Vector3D(_y * v.GetZ() - _z * v.GetY(), _z * v.GetX()
			- _x * v.GetZ(), _x * v.GetY() - _y * v.GetX());
	}

	// Warning: Measures in opposite direction, because of inverted Y axis!
	// Area of parallelepiped defined by this, v1 and v2. It is negative, if
	// looking
	// from this, v1 and v2 not CW, where v1 is on the right
	long long MixedProduct(Vector3D v1, Vector3D v2) {
		return DotProduct(v1.VectorProduct(v2));
	}

	// Warning: Measures in opposite direction, because of inverted Y axis!
	// Angle between two vectors
	long long AngleBetween(Vector3D v, Vector3D lookedFrom) {
		long long angle = acos(Normalize().DotProduct(v.Normalize()));

		// Check the current rotation of vectors
		if (lookedFrom.MixedProduct(v, *this) < 0) {
			angle *= -1;
			angle += 2.0f * M_PI;
		}
		return angle;
	}

	// Distance between two vectors' endpoints
	long long DistanceBetween(Vector3D &v) {
		return Minus(v).GetLength();
	}

	// Project a vector on another one
	long long ProjectionOn(Vector3D &v) {
		return DotProduct(v.Normalize());
	}

	// Warning: Rotates in opposite direction(CW), because of inverted Y
	// axis!
	// Rotate a vector
	Vector3D Rotate(long long angleRad, Vector3D &axis) {
		Vector3D u = axis.Normalize();
		long long ux = u.GetX();
		long long uy = u.GetY();
		long long uz = u.GetZ();
		long long _cos = cos(angleRad);
		long long _sin = sin(angleRad);

		Vector3D x(_cos + ux * ux * (1 - _cos), ux * uy
			* (1 - _cos) - uz * _sin, ux * uz * (1 - _cos) + uy * _sin);
		Vector3D y(uy * ux * (1 - _cos) + uz * _sin, _cos + uy
			* uy * (1 - _cos), uy * uz * (1 - _cos) - ux * _sin);
		Vector3D z(uz * ux * (1 - _cos) - uy * _sin, uz * uy
			* (1 - _cos) + ux * _sin, _cos + uz * uz * (1 - _cos));
		return Vector3D(DotProduct(x), DotProduct(y), DotProduct(z));
	}
};

int main() {
	ifstream ifs("input.in");
	ofstream ofs("output.out");
	long long T;
	ifs >> T;
	for (long long tt = 1; tt <= T; tt++){
		long long N;
		ifs >> N;
		vector<Vector3D> trees(N);
		for (long long i = 0; i < N; i++){
			long long x, y;
			ifs >> x >> y;
			trees[i].SetX(x);
			trees[i].SetY(y);
		}

		ofs << "Case #" << tt << ":" << endl;
		for (long long i = 0; i < N; i++){
			unsigned mineffort = -1;
			for (long long j = 0; j < N; j++){
				if (i == j) continue;
				Vector3D v1 = trees[j].Minus(trees[i]);
				unsigned left = 0;
				unsigned right = 0;
				for (long long k = 0; k < N; k++){
					if (i == k || j == k) continue;
					Vector3D v2 = trees[k].Minus(trees[i]);
					long long res = Vector3D(0,0,1).MixedProduct(v2, v1);
					if (res < 0)
						left++;
					else if ( res > 0 )
						right++;
				}
				mineffort = min(left, min(right, mineffort));
			}
			if (N < 4)
				ofs << 0 << endl;
			else			
				ofs << mineffort << endl;
		}
	}
	return 0;
}
