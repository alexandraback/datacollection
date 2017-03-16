#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <string>


struct Node {
    char ch;
    std::vector<int> counts;
};

void
print_nodes(std::vector<Node> &nodes)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        Node &n = nodes[i];
        printf("%c", n.ch);
        for (int j = 0; j < n.counts.size(); j++)
            printf(" %d", n.counts[j]);
        printf("\n");
    }
    printf("\n");
}

int
calc_min_count(std::vector<int> &counts)
{
    std::sort(counts.begin(), counts.end());
    int num_counts = counts.size();
    int min_val = counts[0];
    int max_val = counts[num_counts-1];
    if (min_val == max_val)
        return 0;

    int min_opers = 0;
    for (int i = 0; i < num_counts; i++)
    {
        int cur_count = counts[i];

        int num_opers = 0;
        for (int j = 0; j < num_counts; j++)
        {
            int this_count = counts[j];
            int op = cur_count - this_count;
            if (op < 0) op = -op;
            num_opers += op;
        }

        if (i == 0 || num_opers < min_opers)
            min_opers = num_opers;
    }
    return min_opers;
}

int
get_count(std::vector<std::string> &strs)
{
    std::vector<Node> nodes;

    struct Node *cur_node = NULL;
    int cur_offset = 0;
    for (int i = 0; i < strs.size(); i++)
    {
        const char *s = strs[i].c_str();
        if (i > 0)
        {
            cur_node = &nodes[0];
            cur_offset = 0;
        }

        for (int j = 0; s[j] != '\0'; j++)
        {
            if (i == 0)
            {
                // this is the first string, so if j == 0 add a new node
                if (j == 0)
                {
                    nodes.push_back(Node());
                    cur_offset = 0;
                    cur_node = &nodes[0];
                    cur_node->ch = s[j];
                    cur_node->counts.push_back(1);
                }
                else
                {
                    if (cur_node->ch != s[j])
                    {
                        nodes.push_back(Node());
                        cur_offset++;
                        cur_node = &nodes[cur_offset];
                        cur_node->ch = s[j];
                        cur_node->counts.push_back(1);
                    }
                    else
                    {
                        // increment the last count
                        cur_node->counts[i] += 1;
                    }
                }
            }
            else
            {
                if (j == 0)
                {
                    if (cur_node->ch != s[j])
                        return -1;

                    // ok, just push back a new character count
                    cur_node->counts.push_back(1);
                }
                else
                {
                    if (cur_node->ch != s[j])
                    {
                        cur_offset++;
                        if (cur_offset >= nodes.size())
                            return -1;

                        cur_node = &nodes[cur_offset];
                        if (cur_node->ch != s[j])
                            return -1;
                        cur_node->counts.push_back(1);
                    }
                    else
                    {
                        cur_node->counts[i] += 1;
                    }
                }
            }
        }

        if (i > 0 && cur_offset < nodes.size() - 1)
            return -1;
    }

    //print_nodes(nodes);
    int num_opers = 0;
    for (int i = 0; i < nodes.size(); i++)
    {
        Node &n = nodes[i];
        int opers = calc_min_count(n.counts);
        //printf("%c - %d\n", n.ch, opers);
        num_opers += opers;
    }

    //exit(0);
    

    return num_opers;
}

int
main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <input.txt>\n", argv[0]);
        return 0;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        printf("Couldn't open file\n");
        return 0;
    }

    char buf[10001];
    fgets(buf, 10001, f);
    int num_tests = atoi(buf);

    //printf("Got %d tests\n", num_tests);

    for (int test_num = 0; test_num < num_tests; test_num++)
    {
        fgets(buf, 10001, f);
        int num_str = atoi(buf);

        std::vector<std::string> strs;

        for (int str_num = 0; str_num < num_str; str_num++)
        {
            fgets(buf, 10001, f);
            char *p = strchr(buf, '\n');
            if (p) *p = '\0';
            strs.push_back(buf);
        }

        int count = get_count(strs);
        const char *response = "Fegla Won";
        if (count >= 0)
        {
            static char nbuf[100];
            sprintf(nbuf, "%d", count);
            response = nbuf;
        }

        printf("Case #%d: %s\n", test_num+1, response);
        
    }

    fclose(f);

    return 0;
}
