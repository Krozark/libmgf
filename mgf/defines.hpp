#ifndef MGF_DEFINES_HPP
#define MGF_DEFINES_HPP

/************************ COLORS *****************************/
#ifdef COLORS

#define MGF_ROUGE  	"\033[31m" ///< couleur rouge pour le terminal
#define MGF_VERT   	"\033[32m" ///< couleur vert pour le terminal
#define MGF_JAUNE  	"\033[33m" ///< couleur jaune
#define MGF_BLEU   	"\033[34m" ///< couleur bleu
#define MGF_MAGENTA "\033[35m" ///< couleur magenta
#define MGF_LMAGENTA "\033[01;35m" ///<couleur magenta claire
#define MGF_BLEU2 "\033[36m" ///< couleur bleu
#define MGF_COMMENTAIRE "\033[31m" ///< couleur pour les commentaires
#define MGF_BLANC 	"\033[00m" ///< couleur par défaut du terminal

#else

#define MGF_ROUGE  	""
#define MGF_VERT   	""
#define MGF_JAUNE  	""
#define MGF_BLEU   	""
#define MGF_MAGENTA ""
#define MGF_LMAGENTA ""
#define MGF_BLEU2 ""
#define MGF_COMMENTAIRE ""
#define MGF_BLANC 	""

#endif
#endif

/***************** MATH ***********************************/
#define MAX(x,y) (x>y?x:y) ///< fonction mathématique max 
#define MIN(x,y) (x<y?x:y) ///< fonction mathématique min


/****************** DEFINES ***********************************/
#define MGF_END_IONS 3


/*********************** DEBUG MODS *************************/
#define MGF_DEBUG_NO 0
#define MGF_DEBUG_LEXER 1<<1

#define MGF_DEBUG_FULL 0xFFFFFFFFFFFFFF

#define MGF_DEBUG MGF_DEBUG_NO

/*************************** DEBUG PRINT ************************/
#if MGF_DEBUG & MGF_DEBUG_LEXER
#define MGF_TOKEN_DEBUG(val) std::cout<<"token: "<<MGF_BLEU<<val<<MGF_BLANC<<std::endl
#else
#define MGF_TOKEN_DEBUG(val) 
#endif

#define MGF_IGNORED(fn) std::cerr<<MGF_JAUNE<<"Function "<<fn<<" Ignored."<<MGF_BLANC<<std::endl;
