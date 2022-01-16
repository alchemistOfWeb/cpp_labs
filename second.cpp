#include <iostream>

int main() {
    int N = 5;
    float arr[N];

    std::cout << "fill the array elements:\n";
    for (int i=0; i<N; i++) {
        std::cout << i << ":\t"; std::cin >> arr[i];
    }

    // find a min element of arr (get index and value)
    float min_ind = 0;
    float min_val = arr[0];

    for (int i=0; i<N; i++) {
        if (arr[i] < min_val) {
            min_ind = i;
            min_val = arr[i];
        }
    }

    std::cout << "\nmin element: " << "\n";
    std::cout << "index: " << min_ind << "\t value: " << min_val << "\n\n";

    // compute sum of elements between first and last positive elements
    int first_positive = -1, last_positive = -1;

    for (int i=0; i<N; i++) {
        if (arr[i] >= 0) {
            if (first_positive < 0) first_positive = i;
            else last_positive = i;
        }
    }

    std::cout << "first positive: " << first_positive << "\t last positive: " << last_positive << "\n";

    if (last_positive >= 0) {
        std::cout << "compute sum of elements between first and last positive elements...\n";
        int elements_sum = 0;

        for (int i=first_positive; i<=last_positive; i++) {
            elements_sum += arr[i];
        }

        std::cout << "sum of elements: " << elements_sum;
    } else {
        std::cout << "There is no positive elements";
    }

    std::cout << std::endl;

    // transforming the array
    int zero_count = 0;

    for (int i=0; i<N; i++) {
        if (arr[i] == 0) {
            int tmp = arr[zero_count];
            arr[zero_count] = arr[i];
            arr[i] = tmp;
            zero_count++;
        }
    }

    std::cout << "transformed array:\n";

    for (int i=0; i<N; i++) {
        std::cout << i << ":\t" << arr[i] << '\n';
    }
} 
