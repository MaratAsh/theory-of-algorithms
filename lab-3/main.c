#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "input.txt"

char	*ft_substr(char *str, char *substr)  
{
	for (unsigned int i = 0; str[i]; ++i) {
		for (unsigned int j = 0;; ++j) {
			if (substr[j] == '\0') return (str + i);
			if (str[i + j] != substr[j]) break;
		}
	}
	return (NULL);
}

void	ft_prefix_function(char *s, int *pi, size_t n) 
{
	pi[0] = 0;
	for (size_t i = 1; i < n; ++i) 
	{
		int j = pi[i - 1];
		while ((j > 0) && (s[i] != s[j]))
			j = pi[j - 1];
		if (s[i] == s[j])
		++j; 
		pi[i] = j;
	}
}

char	*ft_prefix_find(char *str, char *obr, size_t *pi) 
{
	pi[0] = 0;
	size_t	l;
	for (l=1; obr[l]; ++l) 
	{
		size_t j = pi[l - 1];
		while ((j > 0) && (obr[l] != obr[j]))
			j = pi[j - 1];
		if (obr[l] == obr[j])
			++j; 
		pi[l] = j;
     	}
	size_t j = 0;
	for (size_t i=0; str[i]; ++i) 
	{
		while ((j > 0) && (str[i] != obr[j])) 
			j = pi[j - 1];
                  
		if (str[i] == obr[j])
			++j;
		if (j==l)
			return (str + i - l + 1);
	}
	return (NULL);
}


int	main(int argc, char **argv)
{
	FILE	*f;
	char	*file_buff;
	char	buff[64];
	char	*sub;
	struct timeval stop, start;
	double	secs;
	long long	msecs;

	f = fopen(FILENAME, "r");
	if (f == NULL)
	{
		perror(FILENAME);
		return (0);
	}
	file_buff = malloc(1048576);
	memset(file_buff, 0, 1048576);
	memset(buff, 0, sizeof(buff));
	fgets(file_buff, 1048576, f);
	if (argc > 1)
	{
		memcpy(buff, argv[1], 63);
		buff[63] = '\0';
	}
	else
		fgets(buff, sizeof(buff), stdin);
	printf("File '''%s'''\n", file_buff);

	mingw_gettimeofday(&start, NULL);
	sub = ft_substr(file_buff, buff);
	mingw_gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("time O(n*k): %f\n", secs);

	size_t *pi;
	pi = malloc(sizeof(size_t) * strlen(file_buff));
	mingw_gettimeofday(&start, NULL);
	sub = ft_prefix_find(file_buff, buff, pi);
	mingw_gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	msecs = (stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_usec - start.tv_usec);
	printf("time: %f     %lld\n", secs, msecs);

	if (sub == NULL)
		printf("Not Found!\n");
	else
	{
		printf("Found on {%ld} index!\n", sub - file_buff);
		printf("'%s'\n", sub);
	}
	free(file_buff);
	free(pi);
	fclose(f);
}