#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <bsd/string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//#define FT_MEMSET
//#define FT_CALLOC
//#define FT_STRDUP
//#define FT_MEMCMP
//#define FT_MEMCPY
//#define FT_TOUPPER
//#define FT_TOLOWER
//#define FT_ISALNUM
//#define FT_ISASCII
//#define FT_ISALPHA
//#define FT_ISDIGIT
//#define FT_ISPRINT
//#define FT_STRLEN
//#define FT_STRCHR
//#define FT_STRRCHR
//#define FT_MEMCCPY
//#define FT_MEMCHR
//#define FT_BZERO
//#define FT_STRLCAT
//#define FT_MEMMOVE
#define FT_STRNSTR
//#define FT_STRNCMP
//#define FT_STRLCPY
//#define FT_ATOI
//#define FT_SUBSTR
//#define FT_STRJOIN
//#define FT_STRTRIM
//#define FT_SPLIT
//#define FT_ITOA
//#define FT_PUTCHAR_FD
//#define FT_PUTSTR_FD
//#define FT_PUTENDL_FD

//=========================FT_MEMSET==========================
#ifdef FT_MEMSET
#include "ft_memset.c"
void test_ft_memset()
{
	printf("\nTEST DE FT_MEMSET\n");
	int c = 3;
	int n = 7;
	void *s = (void*)malloc(sizeof(int)*n);
	//Est censé retourner un objet, de taille n, contenant la valeur de "c" à chaque case mémoire.
	s = ft_memset(s,c,n); 
	//Vérification
	int i = 0;
	printf("==================================\n");
	printf("Case de départ de s:%p\n",s);
	while(i<n){
		printf("s+%d (mem:%p) = %d\n",i,(s+i),*((int*)s+i));
		i++;
	}
	printf("==================================\n");
}
#endif
//============================================================




//=========================FT_CALLOC==========================
#ifdef FT_CALLOC
#include "../fait/ft_calloc.c"
void test_ft_calloc(){
	printf("\nTEST DE FT_CALLOC\n");
	int nmeb = 4;
	int size = sizeof(int);
	int i = 0;

	int* s = NULL;
	s = (int*)ft_calloc(nmeb, size);

	printf("==================================\n");
	printf("Case de départ de s:%p\n",s);
	while(i<nmeb){
		printf("s+%d (mem:%p) = %d\n",i,(s+i),*((int*)s+i));
		i++;
	}
	printf("==================================\n");

}
#endif
//============================================================




//=========================FT_STRDUP==========================
#ifdef FT_STRDUP
#include "ft_strdup.c"
void test_ft_strdup(){
	printf("\nTEST DE FT_STRDUP\n");
	char input[] = "hola!";
	char *output = ft_strdup(input);
	printf("Input = %s , Output = %s\n", input, output);
}
#endif
//============================================================





//=========================FT_MEMCMP==========================
#ifdef FT_MEMCMP
#include "../ft_memcmp.c"
void test_ft_memcmp(){
	printf("\nTEST FT_MEMCMP\n");

	char* s1 = NULL;
	char* s2 = NULL;
	int n;

	printf("============== CAS 1 ====================\n");
#define S1_1 "t\200"
#define S2_1 "t\0"
	n = 6;
	s1 = (char*)malloc(sizeof(S1_1));
	strcpy(s1, S1_1);
	s2 = (char*)malloc(sizeof(S2_1));
	strcpy(s2, S2_1);
	printf("s1 = %s , s2 = %s, n = %d\n", s1, s2, n);
	printf("Attendu = %d , Obtenu = %d\n", memcmp(s1, s2 , n), ft_memcmp(s1,s2,n));
	free(s1);
	free(s2);
	printf("=========================================\n");

}
#endif
//============================================================


//=========================FT_MEMCPY==========================
#ifdef FT_MEMCPY
#include "../ft_memcpy.c"
void test_ft_memcpy()
{
	void *dest = NULL;
	void *src = NULL;
	int n;
	int size_of_dest;

	printf("TEST DE FT_MEMCPY\n");
	printf("================= CAS 1 =================\n");
	//dest est vide et sa taille est assez grande pour recevoir
	n = 3;
	src = (char*)malloc(sizeof("hola\0"));
	src = "hola\0";
	size_of_dest = sizeof(char)*(n+1) + sizeof("hola\0");
	dest = (char*)malloc (size_of_dest);
	*(char*)dest = 'a';
	printf("dest = %s , src = %s , n = %d\n",dest,src,n);
	printf("ATTENDU  = %s", memcpy(dest,src,n) );
	printf(", OBTENU = %s\n", ft_memcpy(dest,src,n));
	printf("=========================================\n");

	printf("\n");

	printf("================= CAS 2 =================\n");
	//dest n'est pas vide et sa taille est assez grande pour recevoir
	n = 3;
	*(char*)dest = 'a';
	printf("dest = %s , src = %s , n = %d\n",dest,src,n);
	printf("ATTENDU  = %s", memcpy(dest,src,n) );
	//dest = NULL;
	//dest = "a\0";
	printf(", OBTENU = %s\n", ft_memcpy(dest,src,n));
	dest = NULL;
	src = NULL;
	printf("=========================================\n");
	/*

	   printf("\n");

	   printf("================= CAS 3 =================\n");
	//dest est vide et sa taille est trop petite pour recevoir
	n = 3;
	src = "hola\0";
	dest = (char*)malloc(sizeof(char)*(n-1));
	printf("dest = %s , src = %s , n = %d\n",dest,src,n);
	printf("ATTENDU  = %s , OBTENU = %s\n", memcpy(dest,src,n) , ft_memcpy(dest,src,n));
	dest = NULL;
	free(dest);
	src = NULL;
	free(src);
	printf("=========================================\n");

	printf("\n");

	printf("================= CAS 4 =================\n");
	//dest n'est pas vide et sa taille est trop petite pour recevoir
	n = 3;
	src = "hola\0";
	dest = (char*)malloc(sizeof(char)*(n-1));
	dest = "a\0";
	printf("dest = %s , src = %s , n = %d\n",dest,src,n);
	printf("ATTENDU  = %s , OBTENU = %s\n", memcpy(dest,src,n) , ft_memcpy(dest,src,n));
	dest = NULL;
	free(dest);
	src = NULL;
	free(src);
	printf("=========================================\n");
	*/

}
#endif
//============================================================


//=========================FT_TOUPPER==========================
#ifdef FT_TOUPPER
#include "../ft_toupper.c"
void	test_ft_toupper(){
	printf("TEST DE FT_TOUPPER\n");	
	char c = ';';
	printf("%c = %c\n", c,(char)ft_toupper((int)c));
	printf("%c = %c\n", c,(char)toupper((int)c));
}
#endif
//============================================================


//=========================FT_TOLOWER==========================
#ifdef FT_TOLOWER
#include "../ft_tolower.c"
void	test_ft_tolower(){
	printf("TEST DE FT_TOLOWER\n");	
	char c = 'Z';
	printf("%c = %c\n", c,(char)ft_tolower((int)c));
	printf("%c = %c\n", c,(char)tolower((int)c));
}
#endif
//============================================================

//========================= FT_ISALNUM ==========================
#ifdef FT_ISALNUM
#include "../ft_isalnum.c"
void	test_ft_isalnum(){
	printf("TEST DE FT_ISALNUM\n");	
	char c;

	printf("================== CAS 1 ==================\n");
	c = 'a';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isalnum((int)c), ft_isalnum((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 2 ==================\n");
	c = 'A';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isalnum((int)c), ft_isalnum((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	c = '5';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isalnum((int)c), ft_isalnum((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	c = ';';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isalnum((int)c), ft_isalnum((int)c));
	printf("==========================================\n");

}
#endif
//============================================================

//========================= FT_ISASCII ==========================
#ifdef FT_ISASCII 
#include "../ft_isascii.c"
void	test_ft_isascii(){
	printf("TEST DE FT_ISASCII\n");	
	char c;

	printf("================== CAS 1 ==================\n");
	c = 'a';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isascii((int)c), ft_isascii((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 2 ==================\n");
	c = 'A';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isascii((int)c), ft_isascii((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	c = '5';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isascii((int)c), ft_isascii((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	int newc = 689;
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", newc, isascii((int)newc), ft_isascii((int)newc));
	printf("==========================================\n");

}
#endif
//============================================================

//========================= FT_ISALPHA ==========================
#ifdef FT_ISALPHA 
#include "../ft_isalpha.c"
void	test_ft_isalpha(){
	printf("TEST DE FT_ISALPHA\n");	
	char c;

	printf("================== CAS 1 ==================\n");
	c = 'a';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isalpha((int)c), ft_isalpha((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 2 ==================\n");
	c = 'A';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isalpha((int)c), ft_isalpha((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	c = '5';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isalpha((int)c), ft_isalpha((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	int newc = 689;
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", newc, isalpha((int)newc), ft_isalpha((int)newc));
	printf("==========================================\n");

}
#endif
//============================================================


//========================= FT_ISDIGIT ==========================
#ifdef FT_ISDIGIT 
#include "../ft_isdigit.c"
void	test_ft_isdigit(){
	printf("TEST DE FT_ISDIGIT\n");	
	char c;

	printf("================== CAS 1 ==================\n");
	c = 'a';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isdigit((int)c), ft_isdigit((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 2 ==================\n");
	c = 'A';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isdigit((int)c), ft_isdigit((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	c = '5';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isdigit((int)c), ft_isdigit((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	int newc = 689;
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", newc, isdigit((int)newc), ft_isdigit((int)newc));
	printf("==========================================\n");

}
#endif
//============================================================


//========================= FT_ISPRINT ==========================
#ifdef FT_ISPRINT 
#include "../ft_isprint.c"
void	test_ft_isprint(){
	printf("TEST DE FT_ISPRINT\n");	
	char c;

	printf("================== CAS 1 ==================\n");
	c = 'a';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isprint((int)c), ft_isprint((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 2 ==================\n");
	c = 'A';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isprint((int)c), ft_isprint((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	c = '5';
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", c, isprint((int)c), ft_isprint((int)c));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	int newc = 689;
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", newc, isprint((int)newc), ft_isprint((int)newc));
	printf("==========================================\n");


	printf("================== CAS 4 ==================\n");
	newc = 20;
	printf("Pour %c: ATTENDU = %d , RETOURNE = %d\n", newc, isprint((int)newc), ft_isprint((int)newc));
	printf("==========================================\n");
}
#endif
//============================================================




//========================= FT_STRLEN ==========================
#ifdef FT_STRLEN 
#include "../ft_strlen.c"
void	test_ft_strlen(){
	printf("TEST DE FT_STRLEN\n");	

	char *string;

	printf("================== CAS 1 ==================\n");
	string = "abc";
	printf("String = %s , ATTENDU = %lu , OBTENU = %lu\n",string,strlen(string), ft_strlen(string));
	string = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 2 ==================\n");
	string = "abc\0";
	printf("String = %s , ATTENDU = %lu , OBTENU = %lu\n",string,strlen(string), ft_strlen(string));
	string = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	string = "ertyuiokjhgf";
	printf("String = %s , ATTENDU = %lu , OBTENU = %lu\n",string,strlen(string), ft_strlen(string));
	string = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 4 ==================\n");
	string = "";
	printf("String = %s , ATTENDU = %lu , OBTENU = %lu\n",string,strlen(string), ft_strlen(string));
	string = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 5 ==================\n");
	string = "\0";
	printf("String = %s , ATTENDU = %lu , OBTENU = %lu\n",string,strlen(string), ft_strlen(string));
	string = NULL;
	printf("==========================================\n");
}
#endif
//============================================================




//========================= FT_STRCHR ==========================
#ifdef FT_STRCHR 
#include "../ft_strchr.c"
void	test_ft_strchr(){
	printf("TEST DE FT_STRCHR\n");	

	char *string;
	int c;

	printf("================== CAS 1 ==================\n");
	string = "hola";
	c = (int)'a';
	printf("String = %s , caractère = %c\n",string, (char)c);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n",strchr(string,c),strchr(string,c),ft_strchr(string,c),ft_strchr(string,c));
	string = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 2 ==================\n");
	string = "hola\0";
	c = (int)'o';
	printf("String = %s , caractère = %c\n",string, (char)c);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n",strchr(string,c),strchr(string,c),ft_strchr(string,c),ft_strchr(string,c));
	string = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	string = "\0";
	c = (int)'o';
	printf("String = %s , caractère = %c\n",string, (char)c);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n",strchr(string,c),strchr(string,c),ft_strchr(string,c),ft_strchr(string,c));
	string = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 4 ==================\n");
	string = "\0";
	c = (int)'\0';
	printf("String = %s , caractère = %c\n",string, (char)c);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n",strchr(string,c),strchr(string,c),ft_strchr(string,c),ft_strchr(string,c));
	string = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 5 ==================\n");
	printf("==========================================\n");
}
#endif
//============================================================







//========================= FT_STRRCHR ==========================
#ifdef FT_STRRCHR 
#include "../ft_strrchr.c"
void	test_ft_strrchr(){
	printf("TEST DE FT_STRRCHR\n");	

	char *strring;
	int c;

	printf("================== CAS 1 ==================\n");
	strring = "hola";
	c = (int)'a';
	printf("String = %s , caractère = %c\n",strring, (char)c);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n",strrchr(strring,c),strrchr(strring,c),ft_strrchr(strring,c),ft_strrchr(strring,c));
	strring = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 2 ==================\n");
	strring = "holo\0";
	c = (int)'o';
	printf("String = %s , caractère = %c\n",strring, (char)c);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n",strrchr(strring,c),strrchr(strring,c),ft_strrchr(strring,c),ft_strrchr(strring,c));
	strring = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	strring = "\0";
	c = (int)'o';
	printf("String = %s , caractère = %c\n",strring, (char)c);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n",strrchr(strring,c),strrchr(strring,c),ft_strrchr(strring,c),ft_strrchr(strring,c));
	strring = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 4 ==================\n");
	strring = "\0";
	c = (int)'\0';
	printf("String = %s , caractère = %c\n",strring, (char)c);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n",strrchr(strring,c),strrchr(strring,c),ft_strrchr(strring,c),ft_strrchr(strring,c));
	strring = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 5 ==================\n");
	printf("==========================================\n");
}
#endif
//============================================================


//========================= FT_MEMCCPY ==========================
#ifdef FT_MEMCCPY 
#include "../ft_memccpy.c"
void	test_ft_memccpy(){
	printf("TEST DE FT_MEMCCPY\n");	

	void *dest;
	void *src;
	int c;
	size_t n;

	printf("================== CAS 2 ==================\n");
	src = "abcdef";
	dest = calloc(1,strlen(src)*sizeof(char));
	c = (int)'d';
	n = strlen(src);
	printf("dest = %s, src = %s, c = %c, n = %zu\n",dest,src,(char)c,n);
	printf("ATTENDU = src = (%s)%s",memccpy(dest,src,c,n),dest);
	free(dest);
	dest = calloc(1,strlen(src)*sizeof(char));
	printf(", OBTENU = src = (%s)%s\n", ft_memccpy(dest,src,c,n), dest);
	free(dest);
	src = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	src = "abcdef";
	dest = calloc(1,strlen(src)*sizeof(char));
	c = (int)'d';
	n = 2;
	printf("dest = %s, src = %s, c = %c, n = %zu\n",dest,src,(char)c,n);
	printf("ATTENDU = src = (%s)%s",memccpy(dest,src,c,n),dest);
	free(dest);
	dest = calloc(1,strlen(src)*sizeof(char));
	printf(", OBTENU = src = (%s)%s\n", ft_memccpy(dest,src,c,n), dest);
	free(dest);
	src = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 4 ==================\n");
	src = "abcdef";
	dest = calloc(1,strlen(src)*sizeof(char));
	c = (int)'g';
	n = strlen(src);
	printf("dest = %s, src = %s, c = %c, n = %zu\n",dest,src,(char)c,n);
	printf("ATTENDU = src = (%s)%s",memccpy(dest,src,c,n),dest);
	free(dest);
	dest = calloc(1,strlen(src)*sizeof(char));
	printf(", OBTENU = src = (%s)%s\n", ft_memccpy(dest,src,c,n), dest);
	free(dest);
	src = NULL;
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 5 ==================\n");
	src = "abcdef";
	dest = calloc(1,strlen(src)*sizeof(char));
	c = (int)'d';
	n = strlen(src)*2;
	printf("dest = %s, src = %s, c = %c, n = %zu\n",dest,src,(char)c,n);
	printf("ATTENDU = src = (%s)%s",memccpy(dest,src,c,n),dest);
	free(dest);
	dest = calloc(1,strlen(src)*sizeof(char));
	printf(", OBTENU = src = (%s)%s\n", ft_memccpy(dest,src,c,n), dest);
	free(dest);
	src = NULL;
	printf("==========================================\n");
}
#endif
//============================================================
































//========================= FT_MEMCHR ==========================
#ifdef FT_MEMCHR 
#include "../ft_memchr.c"
void	test_ft_memchr(){

	void *s;
	int c;
	size_t n;

	printf("================== CAS 1 ==================\n");
	s = "Hello Hola!";	
	c = 'o';
	n = 6;
	printf("s = %s , c = %c , n = %zu\n", s, (char)c, n);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n", (char*)memchr(s,c,n),memchr(s,c,n),(char*)ft_memchr(s,c,n),ft_memchr(s,c,n));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 2 ==================\n");
	s = "Hello Hola!";	
	c = 'H';
	n = strlen(s);
	printf("s = %s , c = %c , n = %zu\n", s, (char)c, n);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n", (char*)memchr(s,c,n),memchr(s,c,n),(char*)ft_memchr(s,c,n),ft_memchr(s,c,n));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	s = "";	
	c = 'H';
	n = strlen(s);
	printf("s = %s , c = %c , n = %zu\n", s, (char)c, n);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n", (char*)memchr(s,c,n),memchr(s,c,n),(char*)ft_memchr(s,c,n),ft_memchr(s,c,n));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 4 ==================\n");
	s = "Hello Hola";	
	c = 'j';
	n = strlen(s);
	printf("s = %s , c = %c , n = %zu\n", s, (char)c, n);
	printf("ATTENDU = %s(%p) , OBTENU = %s(%p)\n", (char*)memchr(s,c,n),memchr(s,c,n),(char*)ft_memchr(s,c,n),ft_memchr(s,c,n));
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 5 ==================\n");
	printf("==========================================\n");
}
#endif
//============================================================



//================== FT_BZERO ===================
#ifdef FT_BZERO
#include "../ft_bzero.c"
void test_ft_bzero()
{
	printf("TEST DE FT_BZERO\n");

	void *s;
	void *s2;
	size_t n;
	int len1;

	int len2;

	printf("================== CAS 1 ===================\n");
	s = "hello";
	s2 = "hello";
	n = 3;
	len1 = strlen(s);
	len2 = strlen(s2);
	printf("s = %s , n = %zu\n", s , n);
	bzero(s,n);
	ft_bzero(s2,n);
	printf("\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================


//================== STRLCAT ===================
#ifdef FT_STRLCAT
#include "../ft_strlcat.c"
void test_ft_strlcat(){
	printf("TEST DE STRLCAT\n");
	char *dst, *dst2;
	char *src;
	size_t size;


	size_t size_of_new_string;


	printf("================== CAS 1 ===================\n");
	//dst suffisament grand,dst vide, size <= strlen(src) - 1
	src = "Un deux trois quatre cinq";
	size = 5;
	#define DST ""
	dst = (char*)calloc(1,strlen(src) - 1 + strlen(DST)+1);
	printf( "dst = %s(%zu octets) , src = %s (%zu octets) , size = %zu\n", DST, strlen(DST)*sizeof(char), src, strlen(src)*sizeof(char), size);
	size_of_new_string = strlcat(dst,src,size);
	printf("ATTENDU = dst : %s(%zu), ", dst,size_of_new_string);
	dst2 = (char*)calloc(1,strlen(src) - 1 + strlen(DST)+1);
	size_of_new_string = ft_strlcat(dst2,src,size);
	printf("OBTENU = dst : %s(%zu)\n", dst2, size_of_new_string);
	src = NULL;
	#undef DST
	free(dst);
	free(dst2);
	printf("============================================\n");


	printf("\n");
	printf("================== CAS 2 ===================\n");
	//dst suffisament grand, dst non vide, size <= strlen(src) - 1
	src = "Un deux trois quatre cinq";
	size = 5;
	#define DST "5"
	dst = (char*)calloc(1,strlen(src) - 1 + strlen(DST)+1);
	*dst = '5';
	printf( "dst = %s(%zu octets) , src = %s (%zu octets) , size = %zu\n", DST, strlen(DST)*sizeof(char), src, strlen(src)*sizeof(char), size);
	size_of_new_string = strlcat(dst,src,size);
	printf("ATTENDU = dst : %s(%zu), ", dst,size_of_new_string);
	dst2 = (char*)calloc(1,strlen(src) - 1 + strlen(DST)+1);
	*dst2 = '5';
	size_of_new_string = ft_strlcat(dst2,src,size);
	printf("OBTENU = dst : %s(%zu)\n", dst2, size_of_new_string);
	src = NULL;
	#undef DST
	printf("============================================\n");
	printf("\n");
	//printf("================== CAS 3 ===================\n");
	////dst trop petit,dst est vide, size <= strlen(src) - 1
	//PROVOQUE UN SEG FAULT, COMPORTEMENT ATTENDU, TEST VALIDÉ
	//src = "Un deux trois quatre cinq";
	//size = 5;
	//#define DST "4"
	//dst = DST;
	//printf( "dst = %s(%zu octets) , src = %s (%zu octets) , size = %zu\n", DST, strlen(DST)*sizeof(char), src, strlen(src)*sizeof(char), size);
	//size_of_new_string = strlcat(dst,src,size);
	//printf("ATTENDU = dst : %s(%zu), ", dst,size_of_new_string);
	//dst2 = DST;
	//size_of_new_string = ft_strlcat(dst2,src,size);
	//printf("OBTENU = dst : %s(%zu)\n", dst2, size_of_new_string);
	//src = NULL;
	//#undef DST
	//printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	//dst suffisament grand, size > strlen(src) - 1
	src = "Un deux trois quatre cinq";
	size = strlen(src)*2;
	#define DST ""
	dst = calloc(2, strlen(src)*sizeof(char));
	printf( "dst = %s(%zu octets) , src = %s (%zu octets) , size = %zu\n", DST, strlen(DST)*sizeof(char), src, strlen(src)*sizeof(char), size);
	size_of_new_string = strlcat(dst,src,size);
	printf("ATTENDU = dst : %s(%zu), ", dst,size_of_new_string);
	dst2 = calloc(2, strlen(src)*sizeof(char));
	size_of_new_string = ft_strlcat(dst2,src,size);
	printf("OBTENU = dst : %s(%zu)\n", dst2, size_of_new_string);
	src = NULL;
	#undef DST
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================




//================== FT_MEMMOVE ===================
#ifdef FT_MEMMOVE
#include "../ft_memmove.c"
void test_ft_memmove(){
	printf("TEST DE FT_MEMMOVE\n");

	char *dest;
	char *src;
	int n;

	printf("================== CAS 1 ===================\n");
	//dest suffisamment grand
	n = 3;
	src = "abcde";
	dest = (char*)malloc((strlen(src)+1)*sizeof(char));
	printf("dest = %s , src = %s , n = %d\n",dest,src,n);
	printf("ATTENDU = %s ", memmove(dest,src,n));
	free(dest);
	dest = (char*)calloc(1,(strlen(src)+1)*sizeof(char));
	printf(", OBTENU = %s\n",ft_memmove(dest,src,n));
	printf("============================================\n");

	printf("\n");
	printf("================== CAS 2 ===================\n");
	//dest suffisamment grand, n est plus grand que strlen(src)
	src = "abcde";
	n = strlen(src) + 2;
	dest = (char*)malloc(2*(strlen(src)+1)*sizeof(char));
	printf("dest = %s , src = %s , n = %d\n",dest,src,n);
	printf("ATTENDU = %s ", memmove(dest,src,n));
	free(dest);
	dest = (char*)calloc(2,(strlen(src)+1)*sizeof(char));
	printf(", OBTENU = %s\n",ft_memmove(dest,src,n));
	printf("============================================\n");
	printf("\n");



	printf("================== CAS 3 ===================\n");
	//dest trop petit
	src = "abcde";
	n = 3;
	dest = (char*)malloc(sizeof(char)*(n-1));
	printf("dest = %s , src = %s , n = %d\n",dest,src,n);
	printf("ATTENDU = %s ", memmove(dest,src,n));
	free(dest);
	dest = (char*)malloc(sizeof(char)*(n-1));
	printf(", OBTENU = %s\n",ft_memmove(dest,src,n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================



//================== FT_STRNSTR ===================
#ifdef FT_STRNSTR
#include "../ft_strnstr.c"
#include "../ft_strlen.c"
void test_ft_strnstr(){
	printf("TEST DE FT_STRNSTR\n");
	char *big;
	char *little;
	size_t len;

	printf("================== CAS 1 ===================\n");
	big = "Bonjour Bonjour hello";
	little = "Bonjour";
	len = strlen(big);
	printf("big = %s, little = %s, len = %zu\n",big,little,len);
	printf("ATTENDU = %s , OBTENU = %s\n",strnstr(big,little,len),ft_strnstr(big,little,len));
	big = NULL;
	little = NULL;
	len = 0;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	big = "Bonjour Bonjour hello";
	little = "hello";
	len = strlen(little);
	printf("big = %s, little = %s, len = %zu\n",big,little,len);
	printf("ATTENDU = %s , OBTENU = %s\n",strnstr(big,little,len),ft_strnstr(big,little,len));
	big = NULL;
	little = NULL;
	len = 0;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	big = "Bonjour Bonjour hello";
	little = "ha";
	len = strlen(little);
	printf("big = %s, little = %s, len = %zu\n",big,little,len);
	printf("ATTENDU = %s , OBTENU = %s\n",strnstr(big,little,len),ft_strnstr(big,little,len));
	big = NULL;
	little = NULL;
	len = 0;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	big = "Bonjour Bonjour hello";
	little = "hello";
	len = 0;
	printf("big = %s, little = %s, len = %zu\n",big,little,len);
	printf("ATTENDU = %s , OBTENU = %s\n",strnstr(big,little,len),ft_strnstr(big,little,len));
	big = NULL;
	little = NULL;
	len = 0;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	big = "Bonjour Bonjour hello";
	little = "";
	len = strlen(big);
	printf("big = %s, little = %s, len = %zu\n",big,little,len);
	printf("ATTENDU = %s , OBTENU = %s\n",strnstr(big,little,len),ft_strnstr(big,little,len));
	big = NULL;
	little = NULL;
	len = 0;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	big = "lorem ipsum dolor sit amet";
	little = "ipsumm";
	len = 30;
	printf("big = %s, little = %s, len = %zu\n",big,little,len);
	printf("ATTENDU = %s , OBTENU = %s\n",strnstr(big,little,len),ft_strnstr(big,little,len));
	big = NULL;
	little = NULL;
	len = 0;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================




//================== FT_STRNCMP ===================
#ifdef FT_STRNCMP
#include "../ft_strncmp.c"
void test_ft_strncmp(){
	char *s1;
	char *s2;
	size_t n;
	
	printf("TEST DE FT_STRNCMP\n");
	printf("================== CAS 1 ===================\n");
	s1 = "abc";
	s2 = "abd";
	n = strlen(s2);
	printf("s1 = %s, s2 = %s, n = %zu\n",s1,s2,n);
	printf("ATTENDU = %d, OBTENU = %d\n",strncmp(s1,s2,n), ft_strncmp(s1,s2,n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	s1 = "ebc";
	s2 = "abd";
	n = strlen(s2);
	printf("s1 = %s, s2 = %s, n = %zu\n",s1,s2,n);
	printf("ATTENDU = %d, OBTENU = %d\n",strncmp(s1,s2,n), ft_strncmp(s1,s2,n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	s1 = "abc";
	s2 = "abd";
	n = 0;
	printf("s1 = %s, s2 = %s, n = %zu\n",s1,s2,n);
	printf("ATTENDU = %d, OBTENU = %d\n",strncmp(s1,s2,n), ft_strncmp(s1,s2,n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	s1 = "abc";
	s2 = "abc";
	n = strlen(s2);
	printf("s1 = %s, s2 = %s, n = %zu\n",s1,s2,n);
	printf("ATTENDU = %d, OBTENU = %d\n",strncmp(s1,s2,n), ft_strncmp(s1,s2,n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	s1 = "abc";
	s2 = "abc000000000";
	n = strlen(s2);
	printf("s1 = %s, s2 = %s, n = %zu\n",s1,s2,n);
	printf("ATTENDU = %d, OBTENU = %d\n",strncmp(s1,s2,n), ft_strncmp(s1,s2,n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================






//================== FT_STRLCPY ===================
#ifdef FT_STRLCPY
#include "../ft_strlcpy.c"
void test_ft_strlcpy(){
	printf("TEST DE FT_STRLCPY\n");
	char *dst;
	char *src;
	size_t size;

	printf("================== CAS 1 ===================\n");
	src = "abc";
	size = strlen(src);
	dst = (char*)calloc(1,strlen(src)*sizeof(char));
	printf("dst = %s, src = %s, size = %zu\n", dst,src,size);
	printf("ATTENDU = (%zu)%s\n",strlcpy(dst,src,size),dst);
	free(dst);
	dst = (char*)calloc(1,strlen(src)*sizeof(char));
	printf("OBTENU = (%zu)%s\n",ft_strlcpy(dst,src,size),dst);
	src = NULL;
	free(dst);
	size = 0;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	src = "abcdef";
	size = strlen(src);
	dst = (char*)calloc(1,sizeof(char));
	printf("dst = %s, src = %s, size = %zu\n", dst,src,size);
	printf("ATTENDU = (%zu)%s\n",strlcpy(dst,src,size),dst);
	free(dst);
	dst = (char*)calloc(1,sizeof(char));
	printf("OBTENU = (%zu)%s\n",ft_strlcpy(dst,src,size),dst);
	src = NULL;
	free(dst);
	size = 0;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================





//================== FT_ATOI ===================
#ifdef FT_ATOI
#include "../ft_atoi.c"
#include "../ft_strlen.c"
#include "../ft_calloc.c"
#include "../ft_isdigit.c"
void test_ft_atoi(){
	printf("TEST DE FT_ATOI\n");
	char *nptr;
	printf("================== CAS 1 ===================\n");
	nptr = "2a";
	printf("nptr = %s\n", nptr);
	printf("ATTENDU = %d\n", atoi(nptr));
	printf("OBTENU = %d\n",ft_atoi(nptr));
	nptr = NULL;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	nptr = "a2";
	printf("nptr = %s\n", nptr);
	printf("ATTENDU = %d\n", atoi(nptr));
	printf("OBTENU = %d\n",ft_atoi(nptr));
	nptr = NULL;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	nptr = "280";
	printf("nptr = %s\n", nptr);
	printf("ATTENDU = %d\n", atoi(nptr));
	printf("OBTENU = %d\n",ft_atoi(nptr));
	nptr = NULL;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	nptr = "-1";
	printf("nptr = %s\n", nptr);
	printf("ATTENDU = %d\n", atoi(nptr));
	printf("OBTENU = %d\n",ft_atoi(nptr));
	nptr = NULL;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	nptr = "--5";
	printf("nptr = %s\n", nptr);
	printf("ATTENDU = %d\n", atoi(nptr));
	printf("OBTENU = %d\n",ft_atoi(nptr));
	nptr = NULL;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	nptr = "+-5";
	printf("nptr = %s\n", nptr);
	printf("ATTENDU = %d\n", atoi(nptr));
	printf("OBTENU = %d\n",ft_atoi(nptr));
	nptr = NULL;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	nptr = "+5";
	printf("nptr = %s\n", nptr);
	printf("ATTENDU = %d\n", atoi(nptr));
	printf("OBTENU = %d\n",ft_atoi(nptr));
	nptr = NULL;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	nptr = " -46";
	printf("nptr = %s\n", nptr);
	printf("ATTENDU = %d\n", atoi(nptr));
	printf("OBTENU = %d\n",ft_atoi(nptr));
	nptr = NULL;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================



//================== FT_SUBSTR ===================
#ifdef FT_SUBSTR
#include "../ft_substr.c"
void test_ft_substr(){
	printf("TEST DE FT_SUBSTR\n");
	char *s;
	unsigned int start;
	size_t len;
	printf("================== CAS 1 ===================\n");
	s = "Un deux trois";
	start = 8;
	len = 5;
	printf("s = %s , start = %d , len = %zu\n",s,start,len);
	printf("OBTENU = %s\n", ft_substr(s,start,len));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================



//================== FT_STRJOIN ===================
#ifdef FT_STRJOIN
#include "../ft_strjoin.c"
void test_ft_strjoin(){
	printf("TEST DE FT_STRJOIN\n");
	char *s1;
	char *s2;
	printf("================== CAS 1 ===================\n");
	s1 = "Un";
	s2 = "Deux";
	printf("s1 = %s , s2 = %s\n",s1,s2);
	printf("OBTENU = %s\n",ft_strjoin(s1,s2));
	s1 = NULL;
	s2 = NULL;
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================






//================== FT_STRTRIM ===================
#ifdef FT_STRTRIM
#include "../ft_strtrim.c"
void test_ft_strtrim(){
	printf("TEST DE FT_STRTRIM\n");
	char *s;
	char *c;

	printf("================== CAS 1 ===================\n");
	s = " \n\n salut ca va\n\n";
	c = "\n ";
	printf("s = %s , c = '/nESPACE'\n",s);
	printf("OBTENU =|%s|\n",ft_strtrim(s,c));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================




//================== FT_SPLIT ===================
#ifdef FT_SPLIT
#include "../ft_split.c"
void test_ft_split(){
	printf("TEST DE FT_SPLIT\n");
	char *s;
	char c;
	char **rt_array;

	printf("================== CAS 1 ===================\n");
	s = "Hi my name is SLIM SHADY!";
	c = ' ';
	printf("s = |%s| , c = |%c|\n",s,c);
	rt_array = ft_split(s,c);
	for ( int i = 0; rt_array[i][0] != '\0'; i++)
		printf("rt_array[%d] = |%s|\n",i,rt_array[i]);
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================




//================== FT_ITOA ===================
#ifdef FT_ITOA
#include "../ft_itoa.c"
void test_ft_itoa(){
	printf("TEST DE FT_ITOA\n");
	int n;
	printf("================== cas 1 ===================\n");
	n = 653;
	printf("n = %d\n",n);
	printf("obtenu = %s\n",ft_itoa(n));
	printf("============================================\n");
	printf("\n");
	printf("================== cas 2 ===================\n");
	n = 4587;
	printf("n = %d\n",n);
	printf("obtenu = %s\n",ft_itoa(n));
	printf("============================================\n");
	printf("\n");
	printf("================== cas 3 ===================\n");
	n = 0;
	printf("n = %d\n",n);
	printf("obtenu = %s\n",ft_itoa(n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	n = 1002;
	printf("n = %d\n",n);
	printf("OBTENU = %s\n",ft_itoa(n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	n = -100;
	printf("n = %d\n",n);
	printf("OBTENU = %s\n",ft_itoa(n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	n = -32768;
	printf("n = %d\n",n);
	printf("OBTENU = %s\n",ft_itoa(n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	n = 32767;
	printf("n = %d\n",n);
	printf("OBTENU = %s\n",ft_itoa(n));
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================



//================== FT_PUTCHAR_FD ===================
#ifdef FT_PUTCHAR_FD
#include "../ft_putchar_fd.c"
void test_ft_putchar_fd(){
	printf("TEST DE FT_PUTCHAR_FD\n");
	char c;
	int fd = open("/home/user42/projets/libft/notToCommit/test_ft_putchar_fd.txt", O_WRONLY | O_APPEND);  
	printf("================== CAS 1 ===================\n");
	c = 'a';
	ft_putchar_fd(c,fd);
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================



//================== FT_PUTSTR_FD ===================
#ifdef FT_PUTSTR_FD
#include "../ft_putstr_fd.c"
void test_ft_putstr_fd(){
	printf("TEST DE FT_PUTSTR_FD\n");
	char *s;
	int fd = open("/home/user42/projets/libft/notToCommit/test_ft_putstr_fd.txt", O_WRONLY | O_APPEND);  

	printf("================== CAS 1 ===================\n");
	s = "hello";
	ft_putstr_fd(s, fd);
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================



//================== FT_PUTENDL_FD ===================
#ifdef FT_PUTENDL_FD
#include "../ft_putendl_fd.c"
void test_ft_putendl_fd(){
	printf("TEST DE FT_PUTENDL_FD\n");
	char *s;
	int fd = open("/home/user42/projets/libft/notToCommit/test_ft_putendl_fd.txt", O_WRONLY);  

	printf("================== CAS 1 ===================\n");
	s = "hello";
	ft_putendl_fd(s,fd);
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 2 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 3 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 6 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 7 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 8 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 9 ===================\n");
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 10 ===================\n");
	printf("============================================\n");
}
#endif
//===============================================


int main(){
	test_ft_strnstr();
	return 0;
}
