#include "/home/user42/projets/libft/libft.h" 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <bsd/string.h>

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
//#define FT_MEMCCPY -> ECHEC
//#define FT_MEMCHR
//#define FT_BZERO
#define FT_STRLCAT

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
#define S1_1 ""
#define S2_1 "hola\0"
	n = 0;
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
//#include "../ft_memccpy.c"
void	test_ft_memccpy(){
	printf("TEST DE FT_MEMCCPY\n");	

	void *dest;
	void *src;
	int c;
	int n;
	int size_of_src , size_of_dest, new_size_of_dest;

	printf("================== CAS 2 ==================\n");
	const char * text = "Ceci est ma première phrase. Et ceci est ma seconde";
	size_t length = strlen( text );

	// On essaye de trouver la première phrase dans le texte.
	char firstSentence[ length ];
	char * res = memccpy( firstSentence, text, '.', length );

	// On affiche le resultat.
	if ( res != NULL ) {
		printf( "Une phrase entière a été trouvée.\n" );
		printf( "\t%s\n", firstSentence );
	} else {
		printf( "Aucune phrase entière trouvée.\n" );
	}

	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 3 ==================\n");
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 4 ==================\n");
	printf("==========================================\n");

	printf("\n");

	printf("================== CAS 5 ==================\n");
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
	printf("================== CAS 3 ===================\n");
	//dst trop petit, size <= strlen(src) - 1
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 4 ===================\n");
	//dst suffisament grand, size > strlen(src) - 1
	printf("============================================\n");
	printf("\n");
	printf("================== CAS 5 ===================\n");
	//dst trop petit, size > strlen(src) - 1
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
	test_ft_strlcat();
	return 0;
}
