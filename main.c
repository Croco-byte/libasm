/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:54:19 by user42            #+#    #+#             */
/*   Updated: 2021/02/12 16:03:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	check_strlen(void)
{
	printf("---------- ft_strlen tests ---------\n");
	printf("1. String |%s| has length : %lu\n", "Bonjour", ft_strlen("Bonjour"));
	printf("2. String |%s| has length : %lu\n", "hi", ft_strlen("hi"));
	printf("3. String with 52 'A' has length : %lu\n", ft_strlen("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
	printf("4. NULL string returns size : %lu\n", ft_strlen(NULL));
	printf("5. Empty string returns size : %lu\n", ft_strlen(""));
}

void	check_strcpy(void)
{
	printf("\n\n----------- ft_strcpy tests ---------\n");
	char	src[] = "Bonjour !";
	char	dest[20];

	printf("1. Copying string |%s| into destination ... ... ... ", src);
	ft_strcpy(dest, src);
	printf("Destination string contains : |%s|\n", dest);

	char	src2[] = "abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz";
	char	dest2[60];
	printf("2. Copying string |%s| into destination ... ... ... ", src2);
	ft_strcpy(dest2, src2);
	printf("Destination string contains : |%s|\n", dest2);

	char	src3[] = "";
	char	dest3[5];
	printf("3. Copying empty string |%s| into destination ... ... ... ", src3);
	ft_strcpy(dest3, src3);
	printf("Destination string contains : |%s|\n", dest3);

	char	*src4;
	src4 = 0;
	char	dest4[30];
	printf("4. Trying to copy from a NULL source ... ... function returns : %s\n", ft_strcpy(dest4, src4));

	char	src5[] = "Hey";
	char	*dest5;
	dest5 = 0;
	printf("5. Trying to copy to a NULL dest ... ... function returns : %s\n", ft_strcpy(dest5, src5));
}

void	check_strcmp(void)
{
	printf("\n\n------------- ft_strcmp tests ---------------\n");
	char	*str1 = "";
	char	*str2 = "aaaaaaaaaaaaaaaaaaaa";

	printf("1. Comparing |%s| and |%s| ... ... ft_strcmp returns %d (libc returns %d)\n", "ABCD", "ABCE", ft_strcmp("ABCD", "ABCF"), strcmp("ABCD", "ABCF"));
	printf("2. Comparing |%s| and |%s| ... ... ft_strcmp returns %d (libc returns %d)\n", "ABCD", "ABCD", ft_strcmp("ABCD", "ABCD"), strcmp("ABCD", "ABCD"));
	printf("3. Comparing |%s| and |%s| ... ... ft_strcmp returns %d (libc returns %d)\n", "Hi", "Hello", ft_strcmp("Hi", "Hello"), strcmp("Hi", "Hello"));
	printf("4. Comparing |%s| and |%s| ... ... ft_strcmp returns %d (libc returns %d)\n", str1, str2, ft_strcmp(str1, str2), strcmp(str1, str2));
	printf("5. Comparing |%s| and |%s| ... ... ft_strcmp returns %d (libc returns %d)\n", "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxya", ft_strcmp("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxya"), strcmp("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxya"));
}

void	check_write(void)
{
	printf("\n\n------------ ft_write tests -----------------\n");
	int result;
	int fd;
	int fd2;

	fd = open("./testing_files/testing", O_RDWR | O_CREAT, S_IRWXU);
	fd2 = open("./testing_files/testing2", O_RDONLY | O_CREAT, S_IRWXU);

	errno = 0;
	printf("1. Writing 'Hi there' to STDOUT :\n");
	printf("	(ft_write)	");
	result = ft_write(1, "Hi there", 8);
	printf(" <-- errno is %d ('%s'), returns %d\n", errno, strerror(errno), result);
	errno = 0;

	printf("	(libc write)	");
	result = write(1, "Hi there", 8);
	printf(" <-- errno is %d ('%s'), returns %d\n\n\n", errno, strerror(errno), result);
	errno = 0;
	

	printf("2. Writing 'abcdefghijklmnopqrstuvwxyz' to STDERR :\n");
	printf("	(ft_write)	");
	result = ft_write(2, "abcdefghijklmnopqrstuvwxyz", 26);
	printf(" <-- errno is %d ('%s'), returns %d\n", errno, strerror(errno), result);
	errno = 0;

	printf("	(libc write)	");
	result = write(2, "abcdefghijklmnopqrstuvwxyz", 26);
	printf(" <-- errno is %d ('%s'), returns %d\n\n\n", errno, strerror(errno), result);
	errno = 0;


	printf("3. Writing 'Hi' to a wrong file descriptor :\n");
	printf("	(ft_write)	");
	result = ft_write(-1, "Hi", 2);
	printf(" <-- errno is %d ('%s'), returns %d\n", errno, strerror(errno), result);
	errno = 0;

	printf("	(libc write)	");
	result = write(-1, "Hi", 2);
	printf(" <-- errno is %d ('%s'), returns %d\n\n\n", errno, strerror(errno), result);
	errno = 0;


	printf("4. Writing 'I'm in a file' to a the file './testing_files/testing' (check the file) :\n");
	printf("	(ft_write)	");
	result = ft_write(fd, "I'm in a file", 13);
	printf(" <-- errno is %d ('%s'), returns %d\n", errno, strerror(errno), result);
	errno = 0;

	printf("	(libc write)	");
	result = write(fd, "I'm in a file", 13);
	printf(" <-- errno is %d ('%s'), returns %d\n\n\n", errno, strerror(errno), result);
	errno = 0;


	printf("5. Writing 'I'm in a file' to a the file './testing_files/testing2' that is READONLY :\n");
	printf("	(ft_write)	");
	result = ft_write(fd2, "I'm in a file", 13);
	printf(" <-- errno is %d ('%s'), returns %d\n", errno, strerror(errno), result);
	errno = 0;

	printf("	(libc write)	");
	result = write(fd2, "I'm in a file", 13);
	printf(" <-- errno is %d ('%s'), returns %d\n\n\n", errno, strerror(errno), result);
	errno = 0;


	printf("6. Writing 'hey' to STDOUT but the string size if negative :\n");
	printf("	(ft_write)	");
	result = ft_write(fd, "hey", -13);
	printf(" <-- errno is %d ('%s'), returns %d\n", errno, strerror(errno), result);
	errno = 0;

	printf("	(libc write)	");
	result = write(fd, "hey", -13);
	printf(" <-- errno is %d ('%s'), returns %d\n\n\n", errno, strerror(errno), result);
	errno = 0;

	close(fd);
	close(fd2);
	
}

void	check_read(void)
{
	char	buffer[64 + 1];
	int		reader;
	int		fd;
	int		fd2;

	fd = open("./testing_files/read_test1", O_RDONLY, S_IRWXU);
	fd2 = open("./testing_files/read_test2", O_WRONLY, S_IRWXU);

	printf("\n\n------------ ft_read tests -----------------\n");

	printf("1. Trying to read from standard entry, and display what was read\n");
	errno = 0;
	write(1, "ft_read : ", 10);
	reader = ft_read(0, buffer, 64);
	if (reader != -1)
	{
		buffer[reader] = '\0';
		printf("Recieved the string : %s	[function returns %d, errno is %d ('%s')]\n", buffer, reader, errno, strerror(errno));
	}
	else
		printf("Error while reading	\n [function returns %d, errno is %d ('%s')]\n", reader, errno, strerror(errno));

	errno = 0;
	write(1, "libc read : ", 12);
	reader = read(0, buffer, 64);
	if (reader != -1)
	{
		buffer[reader] = '\0';
		printf("Recieved the string : %s	[function returns %d, errno is %d ('%s')]\n", buffer, reader, errno, strerror(errno));
	}
	else
		printf("Error while reading	\n [function returns %d, errno is %d ('%s')]\n", reader, errno, strerror(errno));


	printf("\n\n2. Trying to read from standard entry, but with a wrong read size\n");
	errno = 0;
	write(1, "ft_read : ", 10);
	reader = ft_read(0, buffer, -64);
	if (reader != -1)
	{
		buffer[reader] = '\0';
		printf("Recieved the string : %s	[function returns %d, errno is %d ('%s')]\n", buffer, reader, errno, strerror(errno));
	}
	else
		printf("Error while reading	\n [function returns %d, errno is %d ('%s')]\n", reader, errno, strerror(errno));

	errno = 0;
	write(1, "libc read : ", 12);
	reader = read(0, buffer, -64);
	if (reader != -1)
	{
		buffer[reader] = '\0';
		printf("Recieved the string : %s	[function returns %d, errno is %d ('%s')]\n", buffer, reader, errno, strerror(errno));
	}
	else
		printf("Error while reading	\n [function returns %d, errno is %d ('%s')]\n", reader, errno, strerror(errno));
	

	printf("\n\n3. Trying to read from the file './testing_files/read_test1'\n");
	errno = 0;
	write(1, "ft_read : ", 10);
	reader = ft_read(fd, buffer, 64);
	if (reader != -1)
	{
		buffer[reader] = '\0';
		printf("	Recieved the string :	%s	[function returns %d, errno is %d ('%s')]\n", buffer, reader, errno, strerror(errno));
	}
	else
		printf("Error while reading	\n [function returns %d, errno is %d ('%s')]\n", reader, errno, strerror(errno));

	errno = 0;
	close(fd);
	fd = open("./testing_files/read_test1", O_RDONLY, S_IRWXU);
	write(1, "libc read : ", 12);
	reader = read(fd, buffer, 64);
	if (reader != -1)
	{
		buffer[reader] = '\0';
		printf("	Recieved the string :	%s	[function returns %d, errno is %d ('%s')]\n", buffer, reader, errno, strerror(errno));
	}
	else
		printf("Error while reading	\n [function returns %d, errno is %d ('%s')]\n", reader, errno, strerror(errno));



	printf("\n\n4. Trying to read from the file './testing_files/read_test2' that is WRONLY\n");
	errno = 0;
	write(1, "ft_read : ", 10);
	reader = ft_read(fd2, buffer, 64);
	if (reader != -1)
	{
		buffer[reader] = '\0';
		printf("	Recieved the string :	%s	[function returns %d, errno is %d ('%s')]\n", buffer, reader, errno, strerror(errno));
	}
	else
		printf("Error while reading	\n [function returns %d, errno is %d ('%s')]\n", reader, errno, strerror(errno));

	errno = 0;
	close(fd);
	fd = open("./testing_files/read_test1", O_RDONLY, S_IRWXU);
	write(1, "libc read : ", 12);
	reader = read(fd2, buffer, 64);
	if (reader != -1)
	{
		buffer[reader] = '\0';
		printf("	Recieved the string :	%s	[function returns %d, errno is %d ('%s')]\n", buffer, reader, errno, strerror(errno));
	}
	else
		printf("Error while reading	\n [function returns %d, errno is %d ('%s')]\n", reader, errno, strerror(errno));
}

void	check_strdup(void)
{
	printf("\n\n------------ ft_strdup tests -----------------\n");

	char	str[] = "Simple test";
	char	*result;

	printf("\n1. Simple dup of string 'Simple test'\n");
	errno = 0;
	result = ft_strdup(str);
	printf("ft_strdup returns :	|%s|	<-- length %lu, errno %d ('%s')\n", result, strlen(result), errno, strerror(errno));
	free(result);
	result = strdup(str);
	printf("libc strdup returns :	|%s|	<-- length %lu, errno %d ('%s')\n", result, strlen(result), errno, strerror(errno));
	free(result);

	printf("\n2. Dup of a long string\n");
	errno = 0;
	result = ft_strdup("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
	printf("ft_strdup returns :	|%s|	<-- length %lu, errno %d ('%s')\n", result, strlen(result), errno, strerror(errno));
	free(result);
	result = strdup("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
	printf("libc strdup returns :	|%s|	<-- length %lu, errno %d ('%s')\n", result, strlen(result), errno, strerror(errno));
	free(result);

	printf("\n3. Dup of an empty string\n");
	errno = 0;
	result = ft_strdup("");
	printf("ft_strdup returns :	|%s|	<-- length %lu, errno %d ('%s')\n", result, strlen(result), errno, strerror(errno));
	free(result);
	result = strdup("");
	printf("libc strdup returns :	|%s|	<-- length %lu, errno %d ('%s')\n", result, strlen(result), errno, strerror(errno));
	free(result);

	printf("\n4. Function simulating the behavior of ft_strdup in case malloc fails\n");
	errno = 0;
	ft_malloc_fails();
	printf("Function would return %s	<-- errno %d ('%s')\n", ft_malloc_fails(), errno, strerror(errno));

	printf("\n5. Strdup a NULL string makes both functions crash (ft_strdup and strdup)\n");

}

int		main(void)
{

	check_strlen();
	check_strcpy();
	check_strcmp();
	check_write();
	check_read();
	check_strdup();

	return (0);
}
