#include <iostream>
#include <vector>

using namespace std;

vector<int> closestPrimes(int left, int right) {
    vector<bool> is_prime(right + 1, true);
    vector<int> primes;
    vector<int> result = {-1,-1};   
    int min_gap = right, gap;
    //changing state for 0 and 1 as they are both not prime
    is_prime[0] = false;
    is_prime[1] = false;
    //using Sieve of Eratosthenes to find all the prime numbers
    //in is_prime vector which is initailly all set to true we will update the state to false for every value that is not a prime no.
    //we will find all the prime no.s first and leave them as true, but we will update the state to false for all their multiples in the rest of the vector is_prime
    for (int i = 0; i * i <= right; i++) {
        if(is_prime[i]) {
            for (int j = i * i; j <= right; j += i) {
                is_prime[j] = false;
            }
        }
    }
    //populating a vector is prime with all the prime no.s between left and right
    for (int i = left; i <= right; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }
    //if there are less than 2 prime no.s in the list of primes in the interval it should return default values
    if(primes.size() < 2) {
        return result;
    }
    //looks for the pair of prime no.s in range with the smallest difference
    for(int i = 1; i < primes.size(); i++) {
        gap = primes[i] - primes[i-1];
        if (gap < min_gap) {
            min_gap = gap;
            result = {primes[i-1], primes[i]};
        }
    }
    return result;
}

int main() {
    vector<int> solution1 = closestPrimes(10, 19);              // test case 1
    vector<int> solution2 = closestPrimes(4, 6);                // test case 2
    cout << "[" << solution1[0] << ", " << solution1[1] << "]";
    cout << "[" << solution2[0] << ", " << solution2[1] << "]";
}