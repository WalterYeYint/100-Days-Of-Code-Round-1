
#include <cstdlib>

#include <cmath>
#include <limits>

class Randoms
{
public:
	// Generator seed.
	Randoms(long x) {xpto = -x;}
	// Returns a random Gaussian number
	double Normal (double avg, double sigma) {
		return (avg + sigma * gaussdev(&xpto));
	}
	// Returns a uniform random number between 0 and 1.
	double Uniforme() {
		return ran1(&xpto);
	}
	// Returns a random number between -m and m.
	double sorte(int m) {
		return (1.0 * rand()) / (1.0 * RAND_MAX) * 2.0 * m - m;
	}
	~Randoms()

};