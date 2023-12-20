#pragma once
#include <vector>
namespace Sorted
{
	struct Stats {
		size_t comparison_count;
		size_t copy_count;
		Stats() : comparison_count(0), copy_count(0) {};

		Stats& operator += (const Stats &other) {
			comparison_count += other.comparison_count;
			copy_count += other.copy_count;
			return* this;
		}
	};

	template <typename T>
	Stats bubbleSort(T& arr) {

		Stats stats;
		size_t length = arr.size();
		while (length != 0) {
			size_t max_index = 0;
			for (size_t i = 1; i < length; i++) {
				stats.comparison_count++;
				if (arr[i - 1] > arr[i]) {
					std::swap(arr[i], arr[i - 1]);
					stats.copy_count += 3;
					max_index = i;
				}
			}
			length = max_index;
		}
		return stats;
	};

	template <typename T>
	Stats cocktailSort(T& arr) {
		Stats stats;
		size_t left = 0;
		size_t right = arr.size() - 1;
		bool swapped;
		while (left < right) {
			swapped = false;
			for (int i = left; i < right; i++) {
				stats.comparison_count++;
				if (arr[i] > arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					stats.copy_count += 3;
					swapped = true;
				}
			}
			if (!swapped){
				break;
			}
			right--;
			for (int i = right; i > left; i--) {
				stats.comparison_count++;
				if (arr[i] < arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					stats.copy_count += 3;
				}
			}
			left++;
		}
		return stats;

	};
	template <typename T>
	Stats combSort(T& arr) {
		Stats stats;
		size_t length = arr.size();
		double factor = 1.247;
		float gapFactor = length / factor;
		while (gapFactor >= 1) {
			size_t gap = int(gapFactor);
			for (int i = 0; i < length - gap; i++) {
				stats.comparison_count++;
				if (arr[i] > arr[i + gap]) {
					std::swap(arr[i], arr[i + gap]);
					stats.copy_count += 3;
				};
			}
			gapFactor = gapFactor / factor;
		}
		return stats;

	};

}
