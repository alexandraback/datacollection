#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>


class Tree
{
    friend std::istream& operator>>(std::istream& in, Tree& t);

public:
    int64_t X() const { return x_; };
    int64_t Y() const { return y_; };

    int64_t cross_product(const Tree& t1, const Tree& t3) const
    {
        return (x_ - t1.x_) * (t3.y_ - t1.y_) - (y_ - t1.y_) * (t3.x_ - t1.x_);
    }

    bool is_triangle(const Tree& t1, const Tree& t3) const
    {
        return 0 < cross_product(t1, t3);
    }

    bool is_linear(const Tree& t1, const Tree& t3) const
    {        
        return 0 == cross_product(t1, t3);
    }

    double distance(const Tree& t1, const Tree& t2) const
    {
        double n = std::abs((t2.x_ - t1.x_) * (t1.y_ - y_) - (t1.x_ - x_) * (t2.y_ - t1.y_));

        double d_sq_p1 = t2.x_ - t1.x_;
        double d_sq_p2 = t2.y_ - t1.y_;
        double d = std::sqrt(d_sq_p1 * d_sq_p1 + d_sq_p2 * d_sq_p2);
        return n / d;
    }

    bool operator==(const Tree& rhs) const
    {
        return x_ == rhs.x_ && y_ == rhs.y_;
    }

private:
    int64_t x_;
    int64_t y_;
};

std::istream& operator>>(std::istream& in, Tree& t)
{
    in >> t.x_ >> t.y_;
    return in;
}

std::vector<size_t> convex_hull(const std::vector<Tree>& trees)
{
    // Find min/max x points
    int min_x = std::numeric_limits<int>::max();
    int max_x = std::numeric_limits<int>::min();

    size_t min_x_idx = 0;
    size_t max_x_idx = 0;

    for (size_t i = 0; i < trees.size(); ++i)
    {
        int x = trees[i].X();
        if (x < min_x)
        {
            min_x_idx = i;
            min_x = x;
        }
        else if (x > max_x)
        {
            max_x_idx = i;
            max_x = x;
        }
    }

    std::vector<size_t> convex_hull{ min_x_idx, max_x_idx };

    std::queue<std::pair<size_t, size_t>> to_check;
    to_check.push({ min_x_idx, max_x_idx });
    to_check.push({ max_x_idx, min_x_idx });

    while (!to_check.empty())
    {
        size_t idx1, idx3;
        std::tie(idx1, idx3) = to_check.front();
        to_check.pop();

        const Tree& t1 = trees[idx1];
        const Tree& t3 = trees[idx3];

        double max_dist = -1;
        size_t max_idx = 0;

        for (size_t i = 0; i < trees.size(); ++i)
        {
            if (end(convex_hull) != std::find(begin(convex_hull), end(convex_hull), i))
            {
                continue;
            }

            // Check if it is on the correct side
            if (trees[i].is_triangle(t1, t3))
            {
                double distance = trees[i].distance(t1, t3);
                if (max_dist < distance)
                {
                    max_dist = distance;
                    max_idx = i;
                }
            }
        }

        if (0 < max_dist)
        {
            convex_hull.insert(std::find(begin(convex_hull), end(convex_hull), idx3), max_idx);
            to_check.push({ idx1, max_idx });
            to_check.push({ max_idx, idx3 });
        }
    }
    return convex_hull;
}

size_t number_of_trees_to_chop(size_t idx, std::vector<size_t> hull, const std::vector<Tree>& trees)
{
    const Tree& this_tree = trees[idx];
    for (size_t i = 0; i < hull.size(); ++i)
    {
        if (this_tree.is_linear(trees[hull[i]], trees[hull[(i + 1) % hull.size()]]))
        {
            return 0;
        }
    }
    
    size_t min_removal = std::numeric_limits<size_t>::max();

    for (size_t dist = 2; dist < hull.size(); ++dist)
    {
        for (size_t i = 0; i < hull.size(); ++i)
        {
            const Tree& t1 = trees[hull[i]];
            const Tree& t2 = trees[hull[(i + dist) % hull.size()]];

            if (t1 == this_tree ||t2 == this_tree ||
                (!this_tree.is_triangle(t1, t2) && !this_tree.is_linear(t1, t2)))
            {
                continue;
            }

            double dist = this_tree.distance(t1, t2);
            size_t removals = 0;
            for (auto& t : trees)
            {
                if (t == this_tree
                    || t == t1
                    || t == t2)
                {
                    continue;
                }

                if (removals > min_removal)
                {
                    break;
                }

                if (t.is_triangle(t1, t2) && t.distance(t1, t2) > dist)
                {
                    ++removals;
                }
            }  
            min_removal = std::min(min_removal, removals);
        }
    }
    return min_removal;
}

void print_result(std::ofstream& out, const std::vector<Tree>& trees)
{
    if (trees.size() == 1)
    {
        out << "0\n";
        return;
    }

    auto hull = convex_hull(trees);
    
    for (size_t i = 0; i < trees.size(); ++i)
    {
        if (end(hull) != std::find(begin(hull), end(hull), i))
        {
            out << "0\n";
        }
        else
        {
            out << number_of_trees_to_chop(i, hull, trees) << "\n";
        }
    }
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
        size_t tree_cnt;
        in >> tree_cnt;

        std::vector<Tree> trees(tree_cnt);

        for (auto& t : trees)
        {
            in >> t;
        }
        
        out << "Case #" << caseno << ":" << '\n';
        print_result(out, trees);
    }
    out.flush();
}
