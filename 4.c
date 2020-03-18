# include<stdio.h>
# include <string.h>
# include<stdlib.h>


void merge_sort_strings(char *string1, char *string2, char *merged_string);

char *generate_merge_sort_string(char *string1, char *string2);

int main() {
	/*
 	* Exercise 4 - Merge sort.
 	*/

	// Part 1
    /*	
	char string1[6] = "belly";
	char string2[5] = "beer";
	char merged_string[10];

	merge_sort_strings(string2, string1, merged_string);

	printf("The result is : %s\n", merged_string); 
	*/
	// Part 2
	const int MAX_STRING_LENGTH = 20;
	
	char string1[MAX_STRING_LENGTH];
	char string2[MAX_STRING_LENGTH];

	printf("Enter string1 : ");
	scanf("%s", string1);

	printf("Enter string2 : ");
	scanf("%s", string2);

	char *merged_string = generate_merge_sort_string(string1, string2);
	
	printf("Result is : %s\n", merged_string);

	free(merged_string);
	return 0;
}

void merge_sort_strings(char *string1, char *string2, char *merged_string) {
	int length = strlen(string1) + strlen(string2);
	for (int i = 0; i < length; ++i) { 
		if (*string1 && *string1 < *string2 || !*string2 ) {
			*merged_string = *string1;
			++string1;
		}
		else {
			*merged_string = *string2;
			++string2;
		}
		++merged_string;
	}
	*merged_string = '\0';
}

char *generate_merge_sort_string(char *string1, char *string2) {
	int length = strlen(string1) + strlen(string2);
	char *merged_string = (char*)malloc( (length + 1) * sizeof(char));
	char *merged_string_address = merged_string;
	
	for (int i = 0; i < length; ++i) {
		if (!*string2 || *string1 && *string1 < *string2  ) {
			*merged_string = *string1;
			++string1;
		}
		else {
			*merged_string = *string2;
			++string2;
		}
		++merged_string;
	}
	*merged_string = '\0';
	
	return merged_string_address;
}

