#include <iostream>
#include <Eigen/Eigen>

int main(int, char*[])
{
    Eigen::Vector3i v3;
    v3 << 1, 2, 3;

    for(int i = 0; i < v3.size(); ++i)
    {
        printf("Element %d = %d\n", i, v3[i]);
    }

    return 0;
}
