#include "/home/user42/projets/libft/libft.h" 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//#define FT_MEMSET
//#define FT_CALLOC
//#define FT_STRDUP
//#define FT_MEMCMP
//#define FT_MEMCPY
//#define FT_TOUPPER
//#define FT_TOLOWER
//#define FT_ISALNUM
//#define FT_ISASCII
#define FT_ISALPHA

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


int main(){
	test_ft_isalpha();
	return 0;
}
