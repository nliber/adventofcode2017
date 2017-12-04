#ifndef INVERSECAPTCHA_H_
#define INVERSECAPTCHA_H_

#include <algorithm>
#include <iterator>

template<typename ForwardIterator>
int InverseCaptcha(ForwardIterator first, ForwardIterator last)
{
    int sum{};

    for (ForwardIterator found = first; (found = std::adjacent_find(found, last)) != last; ++found)
        sum += *found - '0';

    if (first != last && *first == *(last - 1))
        sum += *first - '0';

    return sum;

}

template<typename Container>
int InverseCaptcha(Container const& c)
{ return InverseCaptcha(std::begin(c), std::end(c)); }

#endif /* INVERSECAPTCHA_H_ */

