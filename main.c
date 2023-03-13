#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 100

// Definindo os tipos de tokens
enum TokenType {
    NUMBER,   // 0 a 9
    ADD,      // +
    SUBTRACT, // -
    MULTIPLY, // *
    DIVIDE,   // /
    LPAREN,   // (
    RPAREN,   // )
    RAIZ,     // raiz quadrada
    AND,      // &
    OR,       // I
    XOR,      // #
    MENOR,    // <
    MAIOR,    // >
    PONTO_VIRGULA, // ;
    PONTO,     // .
    VIRGULA,  // ,
    ASPAS_DUPLAS,  // "
    APOSTROFE, // '
    SQRT,     // raiz quadrada
    IGUAL,    // =
    ABRE_COLCHETE, // [
    FECHA_COLCHETE, // ]
    ABRE_CHAVE, // {
    FECHA_CHAVE, // }
    PORCENTAGEM, // %
    CIFRAO,   // $
    INTERROGACAO, // ?
    BARRA,    // /
    TIL,      // ~
    ARROBA,   // @
    NUM_TOKEN_TYPES,
    END_OF_FILE
};

// Definindo a estrutura de um token
typedef struct {
    enum TokenType type;
    char value[BUFFER_SIZE];
} Token;

// Lendo o próximo caractere do buffer
char getNextChar() {
    static char buffer[BUFFER_SIZE];
    static char* pBuffer = buffer;
    
    if (*pBuffer == '\0') {
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            return EOF;
        }
        pBuffer = buffer;
    }
    
    return *pBuffer++;
}

// Desfazendo a leitura do último caractere do buffer
void ungetChar() {
    static char buffer[BUFFER_SIZE];
    static char* pBuffer = buffer;
    
    if (pBuffer > buffer) {
        --pBuffer;
    }
}

// Obtendo o próximo token
Token getNextToken() {
    Token token;
    char ch;
    int i = 0;
    
    // Ignorando espaços em branco
    do {
        ch = getNextChar();
    } while (isspace(ch));
    
    // Identificando o tipo de token
    switch (ch) {
        case '+':
            token.type = ADD;
            break;
        case '-':
            token.type = SUBTRACT;
            break;
        case '*':
            token.type = MULTIPLY;
            break;
        case '/':
            token.type = DIVIDE;
            break;
        case '(':
            token.type = LPAREN;
            break;
        case ')':
            token.type = RPAREN;
            break;
        case '[':
            token.type = ABRE_COLCHETE;
            break;
        case ']':
            token.type = FECHA_COLCHETE;
            break;
        case '{':
            token.type = ABRE_CHAVE;
            break;
        case '}':
            token.type = FECHA_CHAVE;
            break;
        case '<':
            token.type = MENOR;
            break;
        case '>':
            token.type = MAIOR;
            break;
        case ';':
            token.type = PONTO_VIRGULA;
            break;
        case '.':
            token.type = PONTO;
            break;
        case ',':
            token.type = VIRGULA;
            break;
        case '\"':
            token.type = ASPAS_DUPLAS;
            break;
        case '\'':
            token.type = APOSTROFE;
            break;
        case '%':
            token.type = PORCENTAGEM;
            break;
        case '$':   
            token.type = CIFRAO;
            break;
        case '?':
            token.type = INTERROGACAO;
            break;
        case '~':
            token.type = TIL;
            break;
        case '@':  
            token.type = ARROBA;
            break;
        case '=':
            token.type = IGUAL;
            break;
        case '&':
            token.type = AND;
            break;
        case 'I':
            token.type = OR;
            break;
        case '#':
            token.type = XOR;
            break;
        case '^':
            token.type = SQRT;
            break;
        case EOF:
            token.type = END_OF_FILE;
            break;
        default:
            if (isdigit(ch)) {
                token.type = NUMBER;
                do {
                    token.value[i++] = ch;
                    ch = getNextChar();
                } while (isdigit(ch));
                ungetChar();
            } else {
                // Caractere inválido
                printf("Caractere inválido: %c\n", ch);
                token.type = END_OF_FILE;
            }
            break;
    }
    
    token.value[i] = '\0';
    return token;
}

int main() {
    Token token;
    
    do {
        token = getNextToken();
        
        switch (token.type) {
            case NUMBER:
                printf("Número: %s\n", token.value);
                break;
            case ADD:
                printf("Soma\n");
                break;
            case SUBTRACT:
                printf("Subtração\n");
                break;
            case MULTIPLY:  
                printf("Multiplicação\n");
                break;
            case DIVIDE:
                printf("Divisão\n");
                break;
            case LPAREN:    
                printf("Abre parênteses\n");
                break;
            case RPAREN:
                printf("Fecha parênteses\n");
                break; 
            case ABRE_COLCHETE: 
                printf("Abre colchetes\n");
                break;
            case FECHA_COLCHETE:    
                printf("Fecha colchetes\n");
                break;
            case ABRE_CHAVE:
                printf("Abre chaves\n");
                break;
            case FECHA_CHAVE:
                printf("Fecha chaves\n");
                break;
            case MENOR:
                printf("Menor que\n");
                break;
            case MAIOR: 
                printf("Maior que\n");
                break;
            case PONTO_VIRGULA:
                printf("Ponto e vírgula\n");
                break;
            case PONTO:
                printf("Ponto\n");
                break;
            case VIRGULA:   
                printf("Vírgula\n");
                break;
            case ASPAS_DUPLAS:  
                printf("Aspas duplas\n");
                break;
            case APOSTROFE:
                printf("Apostrofe\n");
                break;
            case PORCENTAGEM:   
                printf("Porcentagem\n");
                break;
            case CIFRAO:
                printf("Cifrão\n");
                break;
            case INTERROGACAO:  
                printf("Interrogação\n");
                break;
            case TIL:   
                printf("Til\n");
                break;
            case ARROBA:    
                printf("Arroba\n");
                break;
            case IGUAL: 
                printf("Igual\n");
                break;
            case AND:
                printf("E\n");
                break;
            case OR:
                printf("OU\n");
                break;
            case XOR:
                printf("XOR\n");
                break;
            case SQRT:
                printf("Raiz quadrada\n");
                break;
            case END_OF_FILE:
                printf("Fim do arquivo\n");
                break;
            default:
                // Tipo de token desconhecido
                printf("Tipo de token desconhecido\n");
                break;
        }
    } while (token.type != END_OF_FILE);
    
    return 0;
}
        
