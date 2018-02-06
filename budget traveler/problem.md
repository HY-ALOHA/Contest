# Budget Traveler
**Time Limit - 2 seconds, Memory Limit - 256MB**


Jaeseok, traveling around the world, is a budget traveler. He loves traveling, but does not have much money. He got a free coupon for air tickets from his city to any city and from any city to his city. With the coupon, he is trying to optimize his itinerary only considering the transportation costs between cities that he wants to visit as long as visiting all the cities so that he could use the money on tasty local foods and the sightseeing. Exciting!

## Input
For each test case, the first line contains the number of the cities except for his own one, $1 \le N \le 10^5$, and the number of transportations between the cities, $0 \le M \le 10^6$, separated by a single space.  
In following $M$ lines, each line contains the indices of two terminal cities of a transportation, $1 \le s_i \le N$, and $1 \le d_i \le N$, and the cost between city $s_i$ to city $d_i$, $0 \le c_i \le 10^9$ where $s_i \ne d_i$ and $c_i$ is always integer, separated by a single space.  
All the transportations are bidirectional. The costs of both directions are the same. There may be more than one transportation between the cities.  
In the last line, his budget for the whole transportation, $0 \le B \le 10^{16}$, is given.

## Output
Print the total cost. If he can't afford to travel all the cities within his budget or is not able to do, print $-1$.

## Sample Input
```
3 3
1 2 1
2 3 2
1 3 3
4
```

## Sample Output
```
3
```


#### Author : 허재석

#### Solution
General MST problem. $O(MlogN)$  
Use 64-bit integer.  
**Check that all the nodes are connected after constructing MST**
