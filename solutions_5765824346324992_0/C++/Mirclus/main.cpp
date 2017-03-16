#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

size_t gcd(size_t u, size_t v)
{
    // GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0
    if (u == 0)
    {
        return v;
    }
    if (v == 0)
    {
        return u;
    }

    // Let shift := lg K, where K is the greatest power of 2
    // dividing both u and v.
    int shift;
    for (shift = 0; ((u | v) & 1) == 0; ++shift)
    {
        u >>= 1;
        v >>= 1;
    }

    while ((u & 1) == 0)
    {
        u >>= 1;
    }

    // From here on, u is always odd.
    do
    {
        // remove all factors of 2 in v -- they are not common
        //   note: v is not zero, so while will terminate
        while ((v & 1) == 0)
        {
            v >>= 1;
        }
        // Now u and v are both odd. Swap if necessary so u <= v,
        // then set v = v - u (which is even).
        if (u > v)
        {
            std::swap(u, v);
        }
        v -= u;
    } while (v != 0);

    return u << shift;
}
size_t lcm(size_t u, size_t v)
{
    if (0 == u || 0 == v)
    {
        return 0;
    }

    return u / gcd(u, v) * v;
}

struct Barber
{
    Barber(size_t id, size_t add) : id(id), add(add), time(0) {}    
    
    size_t id;
    size_t add;
    size_t time;
};

bool operator<(const Barber& b1, const Barber& b2)
{
    if (b1.time == b2.time)
    {
        return b1.id > b2.id;
    }
    else
    {
        return b1.time > b2.time;
    }
}

size_t solve(size_t place_in_line, const std::vector<size_t>& times)
{
    // make 0 based
    --place_in_line;

    size_t total_lcm = 1;
    for (auto t : times)
    {
        total_lcm = lcm(total_lcm, t);
    }


    size_t period_customers = 0;
    for (auto t : times)
    {
        period_customers += total_lcm / t;
    }

    // Start over at the beginning
    place_in_line %= period_customers;

    std::priority_queue<Barber> next_barber;
    for (size_t i = 0; i < times.size(); ++i)
    {
        Barber b{ i + 1, times[i] };
        next_barber.push(b);
    }

    while (place_in_line > 0)
    {
        Barber b = next_barber.top();
        next_barber.pop();
        b.time += b.add;
        next_barber.push(b);
        --place_in_line;
    }
    return next_barber.top().id;
}

int main(int argc, char** argv)
{
    if (2 > argc)
    {
        std::cerr << argv[0] << " inputfile [outputfile]" << std::endl;
        return 1;
    }
    std::string infile{argv[1]};
    std::string outfile{infile};
    if (2 < argc)
    {
        outfile = argv[2];
    }
    else
    {
        outfile += ".out";
    }

    std::ifstream in(infile);
    std::ofstream out(outfile);
    if (!in.good())
    {
        std::cerr << "Bad input file" << std::endl;
        return 2;
    }

    if (!out.good())
    {
        std::cerr << "Bad output file" << std::endl;
        return 3;
    }

    int cases;
    in >> cases;

    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        size_t barbers, place_in_line;
        in >> barbers >> place_in_line;

        std::vector<size_t> times(barbers);
        for (auto& t : times)
        {
            in >> t;
        }
        
        out << "Case #" << caseno << ": " << solve(place_in_line, times) << '\n';
    }
    out.flush();
}
