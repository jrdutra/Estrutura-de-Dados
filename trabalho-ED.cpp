/*
================================================================================
Programa DESENVOLVIDO para a disciplina Estrutura de Dados
Aluno: João Ricardo Côre Dutra
Curso: Engenharia da Computação
Instituição: Faculdade Salesiana Maria Auxiliadora
Versão: 0.9 (corresponde a atividade ED-7, ED-08 e ad anteriores presente no EAD)
================================================================================
*/
//Inclusão de bilbiotecas
#include <stdio.h>
#include <windows.h>
#include <conio.h>//Biblioteca para mudar cores da tela
#include <string.h>//Para usar strcpy
#include <time.h>
/*
================================================================================
                          STRUCTS PRESENTES NO PROGRAMA
================================================================================
*/
	struct item{ 
			   int codigo;
               char descricao[5000]; 
               float novo_valor;
               float valor_custo;
               float valor_auxiliar;
               int porte;
               int filme;};
    struct data{
    	        int dia;
    	        int mes;
    	        int ano;
	};                   
    struct consulta{
    			int numero_consulta;
    			char nome_paciente[5000];
    			struct data data_consulta;
    			struct item item_consulta;
	};
	struct indice_consulta{
    			int numero_consulta;
    		    int NRR;
	};
	struct bloco_consulta{
    			char titulo[300];
    		    struct consulta vetorConsultas[11];
	};
	struct bloco_consulta20{
    			char titulo[300];
    		    struct consulta vetorConsultas[20];
	};
	struct nodo_consulta{
				struct consulta vConsulta;
				struct nodo_consulta *p;			
	};
	struct nodo_duplo_consulta{
				struct consulta vConsulta;
				struct nodo_duplo_consulta *F;
				struct nodo_duplo_consulta *T;			
	};
/*
================================================================================
                          Variaveis Globais e Ponteiros
================================================================================
*/
struct nodo_consulta *PE1;
struct nodo_duplo_consulta *pF;
struct nodo_duplo_consulta *pT;
/*
================================================================================
                                FUNÇÕES GENERICAS
================================================================================
*/
void func_gen_configurar_janela(){
         system("title Consultório Médico");
         system("mode con:cols=120 lines=3000");
         system("color f0");
     }
/*
Descricao: 
func_gen_titulo(txt_l1, txt_l2, txt_l3, cor_linha3,txt_l4, txt_l5)
*/
void func_gen_titulo(char l1[], char l2[], char l3[], int cor,char l4[],char l5[])
{
         int i,espacamento, qt_caractere, qt_printada;
         espacamento=4;
         qt_caractere=110;
         HANDLE hConsole;
         hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(hConsole, 31);
          //Da um espaçamento azul
         for(i=0; i<120;i++)
             {
              printf(" ");
             }
         //Da um espaçamanto a esqueda da caixa             
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Canto superior esquerdo
         printf("%c", 201); 
         //Escreve Linhas duplas
         for(i=0; i<qt_caractere;i++)
             {
              printf("%c", 205);
             }
         //Canto superior direito
         printf("%c", 187);
         //Escreve Espaços até o Final da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
         {
          printf(" ");
         }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 186);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l1);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
         {
          printf(" ");
         }
         //Escreve barra vertical a direita do texto
         printf("%c", 186);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 186);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l2);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
             {
              printf(" ");
             }
         //Escreve barra vertical a direita do texto
         printf("%c", 186);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 186);
         //muda a cor do text oda ultima linha
         SetConsoleTextAttribute(hConsole, cor);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l3);
         //retorna para a cor zul e letra branca
         SetConsoleTextAttribute(hConsole, 31);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
             {
              printf(" ");
             }
         //Escreve barra vertical a direita do texto
         printf("%c", 186);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 186);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l4);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
             {
              printf(" ");
             }
         //Escreve barra vertical a direita do texto
         printf("%c", 186);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 186);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l5);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
             {
              printf(" ");
             }
         //Escreve barra vertical a direita do texto
         printf("%c", 186);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //escreve espaço a esqueda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve canto inferior esquedo
         printf("%c", 200);
         //Escreve barra horizontal
         for(i=0; i<qt_caractere;i++)
             {
               printf("%c", 205);
             }
         //Escreve canto inferior direito do quadrado
         printf("%c", 188);
         //Dá espaço ate o final da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
         {
          printf(" ");
         }
         //Dá espaço abaixo do quadrado
         for(i=0; i<120;i++)
             {
              printf(" ");
             }
         //Escreve linha preda abaixo to topo azul
         SetConsoleTextAttribute(hConsole, 0);//escreve linha preta
         for(i=0; i<120 ;i++)
             {
              printf(" ");
             }  
         //retorna para a cor original da janela
         SetConsoleTextAttribute(hConsole, 240);
     }
/*
Descricao: func_gen_quadrado_simples(txt_l1, txt_l2, txt_l3, txt_l4, txt_l5, qt_de_linhas_de_espacamento_acima_e_abaixo_da_caixa)
*/
void func_gen_quadrado_simples(char l1[],char l2[], char l3[],char l4[],char l5[], int qt_linha)
{
         int i,espacamento, qt_caractere,qt_printada;
         espacamento=4;
         qt_caractere=110;
         HANDLE hConsole;
         hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(hConsole, 240);
          //Da um espaçamento azul
         for(i=0; i<(qt_linha*120);i++)
             {
              printf(" ");
             }
         //Da um espaçamanto a esqueda da caixa             
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Canto superior esquerdo
         printf("%c", 218); 
         //Escreve Linhas duplas
         for(i=0; i<qt_caractere;i++)
             {
              printf("%c", 196);
             }
         //Canto superior direito
         printf("%c", 191);
         //Escreve Espaços até o Final da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 179);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l1);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
             {
              printf(" ");
             }
         //Escreve barra vertical a direita do texto
         printf("%c", 179);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 179);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l2);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
             {
              printf(" ");
             }
         //Escreve barra vertical a direita do texto
         printf("%c", 179);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 179);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l3);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
             {
              printf(" ");
             }
         //Escreve barra vertical a direita do texto
         printf("%c", 179);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 179);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l4);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
             {
              printf(" ");
             }
         //Escreve barra vertical a direita do texto
         printf("%c", 179);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Escreve espaçamento a esquerda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve uma Barra vertical
         printf("%c", 179);
         //Escreve Texto da caixa
         qt_printada=printf("%s",l5);
         //Escreve quantidade de espaços restantes ate o final do quadrado
         for(i=0; i<(qt_caractere-qt_printada);i++)
             {
              printf(" ");
             }
         //Escreve barra vertical a direita do texto
         printf("%c", 179);
         //Escreve espaço até o fim da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //escreve espaço a esqueda do quadrado
         for(i=0; i<espacamento;i++)
             {
              printf(" ");
             }
         //Escreve canto inferior esquedo
         printf("%c", 192);
         //Escreve barra horizontal
         for(i=0; i<qt_caractere;i++)
             {
               printf("%c", 196);
             }
         //Escreve canto inferior direito do quadrado
         printf("%c", 217);
         //Dá espaço ate o final da linha
         for(i=0; i<(120-(espacamento+(qt_caractere+2)));i++)
             {
              printf(" ");
             }
         //Dá espaço abaixo do quadrado
         for(i=0; i<(qt_linha*120);i++)
             {
              printf(" ");
             }
}
void func_gen_ler_tag(char _tag[100], char _nome_arquivo[100], char *_texto_lido, int _posicao_inicial, int *_posicao_final)
{
        int cursor;
        int nivel_lin=0;
        int nivel_tag=0;
        int indice_lin;//Inice para a linha capiturada
        int indice_tex;//indice para o texto
        int indice_tag;//indice para a tag
        char linha[5001];
        char texto[5001];
        char tag[100];
        FILE *fp;
        strcpy(tag,_tag);
        fp = fopen (_nome_arquivo, "r+");
        fseek( fp, _posicao_inicial, SEEK_SET );//posiciona o cursor
        fgets (linha, 5001, fp);//pega a linha
        indice_tex=0;
        indice_tag=0;
        for(indice_lin=0;indice_lin<5000;indice_lin++)//PERCORRE A LINHA
        {
             if(linha[indice_lin]=='<')//Procurando o inicio de uma tag
             {
                 nivel_lin=1;
             }
             
             if(linha[indice_lin] == '\0')
             {//sai do loop se encontrar o final do texto digitado
                 break;
             }
             
             if(nivel_lin==1)//Se estiver dentro da tag, descobre se é a tag encontrada
             {   
                 if(linha[indice_lin]==tag[indice_tag])
                 {                            
                   if(linha[indice_lin]=='>')//Procurando o fim da tag enquanto a pesquisa esta verificando a mesma tag procurada
                     {
                      nivel_lin=0;
                      nivel_tag=1;
                      indice_tag=0;
                      indice_lin++;//soma mais um no indice da linha para nao pegar o >
                     }                             
                 }
                 else //Se nao for a tag encontrada zera nivel_lin para continuar procurando a tag
                 {
                   nivel_lin=0;
                   indice_tag=-1;//-1 para quando sair daqui, zerar o indice da tag
                 }
                 indice_tag++;
             }
             if(nivel_tag==1)//Enquanto nivel_tag==1 vai copiando o texto
             {                        
                 texto[indice_tex]=linha[indice_lin];
                 indice_tex++;
                 if(linha[indice_lin+1]=='<' && linha[indice_lin+2]=='/')//Procurando o inicio de uma tag de fechamento
                 {
                  nivel_tag=0;
                  texto[indice_tex]='\0';//finaliza linha
                  break;//sai do loop apos ler o texto dentro da tag
                  
                 }           
             }
        }//finaliza o for
        *_posicao_final=indice_lin+1;
        strcpy(_texto_lido,texto);
        fclose(fp);
        return;
}
void func_gen_ler_vetor_consultas(struct consulta *_consulta, int n)
{      
    int i;
    int verifica;
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];//usado para auxiliar a leitura do XML
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");//instancia do arquivo xml
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
    //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo XML nao esxiste. Va ate o TAD-03, opcao (1) e crie o arquivo.\n\n\n");
        system("PAUSE");
      	(_consulta+1)->numero_consulta=-1;
        return;
      }
      fclose (arquivo);
      //comeca a leitura das consultas
      for (i=0;i<225;i++)//Pula 225 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      //comeca a ler o vetor de consulta no arquivo xml
      for(i=0;i<n;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<numero_consulta>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->numero_consulta=atoi(texto);
          //lendo nome do paciente
          func_gen_ler_tag("<nome_paciente>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          strcpy((*(_consulta+i)).nome_paciente,texto);
          //////////////////////////
          //Lendo Data da consulta//
          //////////////////////////
           //lendo dia
          func_gen_ler_tag("<dia>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->data_consulta.dia=atoi(texto);
           //lendo mes
          func_gen_ler_tag("<mes>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->data_consulta.mes=atoi(texto);
          //lendo ano
          func_gen_ler_tag("<ano>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->data_consulta.ano=atoi(texto);
          //////////////////////////
          //Lendo Item da consulta//
          //////////////////////////
           //lendo codigo
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.codigo=atoi(texto);
          //lendo descricao
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          strcpy((*(_consulta+i)).item_consulta.descricao,texto);
          //lendo <novo_valor>
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.novo_valor=atof(texto);
          //lendo <valor_custo>
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.valor_custo=atof(texto);
          //lendo <valor_auxiliar>
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.valor_auxiliar=atof(texto);
           //lendo <porte>
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.porte=atoi(texto);
           //lendo <filme>
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.filme=atoi(texto);
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
      }
      return;
}
void func_gen_ler_vetor_consultas_do_ED12(struct consulta *_consulta, int n)
{      
    int i;
    int verifica;
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];//usado para auxiliar a leitura do XML
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");//instancia do arquivo xml
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
    //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo XML nao esxiste. Va ate o TAD-03, opcao (1) e crie o arquivo.\n\n\n");
        system("PAUSE");
      	(_consulta+1)->numero_consulta=-1;
        return;
      }
      fclose (arquivo);
      //comeca a leitura das consultas
      for (i=0;i<248;i++)//Pula 248 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      //comeca a ler o vetor de consulta no arquivo xml
      for(i=0;i<n;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<numero_consulta>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->numero_consulta=atoi(texto);
          //lendo nome do paciente
          func_gen_ler_tag("<nome_paciente>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          strcpy((*(_consulta+i)).nome_paciente,texto);
          //////////////////////////
          //Lendo Data da consulta//
          //////////////////////////
           //lendo dia
          func_gen_ler_tag("<dia>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->data_consulta.dia=atoi(texto);
           //lendo mes
          func_gen_ler_tag("<mes>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->data_consulta.mes=atoi(texto);
          //lendo ano
          func_gen_ler_tag("<ano>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->data_consulta.ano=atoi(texto);
          //////////////////////////
          //Lendo Item da consulta//
          //////////////////////////
           //lendo codigo
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.codigo=atoi(texto);
          //lendo descricao
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          strcpy((*(_consulta+i)).item_consulta.descricao,texto);
          //lendo <novo_valor>
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.novo_valor=atof(texto);
          //lendo <valor_custo>
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.valor_custo=atof(texto);
          //lendo <valor_auxiliar>
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.valor_auxiliar=atof(texto);
           //lendo <porte>
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.porte=atoi(texto);
           //lendo <filme>
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          (_consulta+i)->item_consulta.filme=atoi(texto);
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
      }
      return;
}
void func_gen_push_nodo(struct nodo_consulta *p, struct nodo_consulta nodo){
		//atribui as informacoes no primeiro nodo
		p->vConsulta.numero_consulta=nodo.vConsulta.numero_consulta;
		strcpy((*p).vConsulta.nome_paciente,nodo.vConsulta.nome_paciente);
		p->vConsulta.data_consulta=nodo.vConsulta.data_consulta;
		p->vConsulta.item_consulta=nodo.vConsulta.item_consulta;
		return;
}
void func_gen_push_nodo_duplo(struct nodo_duplo_consulta *p, struct nodo_duplo_consulta nodo){
		//atribui as informacoes no primeiro nodo
		p->vConsulta.numero_consulta=nodo.vConsulta.numero_consulta;
		strcpy((*p).vConsulta.nome_paciente,nodo.vConsulta.nome_paciente);
		p->vConsulta.data_consulta=nodo.vConsulta.data_consulta;
		p->vConsulta.item_consulta=nodo.vConsulta.item_consulta;
		p->T=nodo.T;
		p->F=nodo.F;
		return;
}
void func_gen_linhap()
{        
         int i;
         HANDLE hConsole;
         hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
         SetConsoleTextAttribute(hConsole, 0);//escreve linha preta
         for(i=0; i<120 ;i++)
         {
             printf(" ");
         }  
         //retorna para a cor original da janela
         SetConsoleTextAttribute(hConsole, 240);   
}
void func_gen_linhac()
{        
         int i;
         HANDLE hConsole;
         hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
         SetConsoleTextAttribute(hConsole, 119);//escreve linha preta
         for(i=0; i<120 ;i++)
         {
             printf(" ");
         }  
         //retorna para a cor original da janela
         SetConsoleTextAttribute(hConsole, 240);   
}
void func_gen_limpa_tela()
{
         system("cls");
}
void func_gen_menu()
{
         printf("\n\n\n\n");
         printf("%-20s %-40s%s\n"," ", "( 1)ED -01 -> Tema", "(11)ED -11 -> Alocacao Estatica");
         printf("%-20s %-40s%s\n"," ", "( 2)ED -02 -> Funcao", "(12)ED -12 -> Alocacao Dinamica");
         printf("%-20s %-40s%s\n"," ", "( 3)ED -03 -> Arquivo XML", "(13)ED -13 -> Lista Simples e Dupla");
         printf("%-20s %-40s%s\n"," ", "( 4)ED -04 -> Arquivo Binario", "(14)ED -14 -> Recursividade em Lista");
         printf("%-20s %-40s%s\n"," ", "( 5)ED -05 -> Vetor e Matriz", "(15)ED -15 -> Pilha");
         printf("%-20s %-40s%s\n"," ", "( 6)ED -06 -> BubbleSort e PB", "(16)ED -16 -> Funcao Push-Pop");
         printf("%-20s %-40s%s\n"," ", "( 7)ED -07 -> Estrutura", "(17)ED -17 -> Fila");
         printf("%-20s %-40s%s\n"," ", "( 8)ED -08 -> Estrutura Complexa", "(18)ED -18 -> Funcao Enqueue-Dequeue");
         printf("%-20s %-40s%s\n"," ", "( 9)ED -09 -> Arquivo Textual", "(19)ED -19 -> Fila Circular"); 
         printf("%-20s %-40s%s\n"," ", "(10)ED -10 -> Arquivo Binario", "(20)ED -20 -> Ordenacao de Lista");              
         printf("%-20s %-40s\n"," ", "( 0)Sair");
         printf("\n\n\n\n");
         
}
//Funcoes genericas recursivas
void func_gen_exibir_lista_pF(struct nodo_duplo_consulta *p){
					if((*p).T==NULL)
					{
						HANDLE hConsole;
				    	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						printf(" Endereco deste nodo: %d\n",p);
						SetConsoleTextAttribute(hConsole, 240);
						printf("Numero da Consulta: %d\n", (*p).vConsulta.numero_consulta);
						printf("Nome do Paciente  : %s\n", (*p).vConsulta.nome_paciente);
						printf("Data da Consulta  : %d/%d/%d\n", (*p).vConsulta.data_consulta.dia,(*pT).vConsulta.data_consulta.mes,(*pT).vConsulta.data_consulta.ano);
						SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
						printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
						SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
						printf("Codigo            : %d\n", (*p).vConsulta.item_consulta.codigo);
						printf("Descricao         : %s\n", (*p).vConsulta.item_consulta.descricao);
						printf("Novo Valor        : R$%0.2f \n", (*p).vConsulta.item_consulta.novo_valor);
						printf("Valor Custo       : R$%0.2f\n", (*p).vConsulta.item_consulta.valor_custo);
						printf("Valor Auxiliar    : R$%0.2f\n", (*p).vConsulta.item_consulta.valor_auxiliar);
						printf("Porte             : %d\n", (*p).vConsulta.item_consulta.porte);
						printf("Filme             : %d\n", (*p).vConsulta.item_consulta.filme);
						printf("-------------------------\n");
						printf("        PONTEIROS:\n");
						printf("nodo.T: %d\n",(*p).T);
						printf("nodo.F: %d\n",(*p).F);
						printf("-------------------------\n");
						func_gen_linhac();
						return;
					}
					else
					{
						func_gen_exibir_lista_pF((*p).T);
						HANDLE hConsole;
				    	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						printf(" Endereco deste nodo: %d\n",p);
						SetConsoleTextAttribute(hConsole, 240);
						printf("Numero da Consulta: %d\n", (*p).vConsulta.numero_consulta);
						printf("Nome do Paciente  : %s\n", (*p).vConsulta.nome_paciente);
						printf("Data da Consulta  : %d/%d/%d\n", (*p).vConsulta.data_consulta.dia,(*pT).vConsulta.data_consulta.mes,(*pT).vConsulta.data_consulta.ano);
						SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
						printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
						SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
						printf("Codigo            : %d\n", (*p).vConsulta.item_consulta.codigo);
						printf("Descricao         : %s\n", (*p).vConsulta.item_consulta.descricao);
						printf("Novo Valor        : R$%0.2f \n", (*p).vConsulta.item_consulta.novo_valor);
						printf("Valor Custo       : R$%0.2f\n", (*p).vConsulta.item_consulta.valor_custo);
						printf("Valor Auxiliar    : R$%0.2f\n", (*p).vConsulta.item_consulta.valor_auxiliar);
						printf("Porte             : %d\n", (*p).vConsulta.item_consulta.porte);
						printf("Filme             : %d\n", (*p).vConsulta.item_consulta.filme);
						printf("-------------------------\n");
						printf("        PONTEIROS:\n");
						printf("nodo.T: %d\n",(*p).T);
						printf("nodo.F: %d\n",(*p).F);
						printf("-------------------------\n");
						func_gen_linhac();
				}
				return;
}
/*
================================================================================
                          FUNÇÕES DE TERCEIRO NIVEL DE MENU
================================================================================
*/
void func_03_01_01_escrever_arquivo_xml()
{    
        func_gen_titulo("  Menu Principal->ED-03 Arquivo XML",
                        " ",
                        "                                     Escrevendo Arquivo XML", 31,
                        "                                   Utilizando a funcao fprintf() ",
                        " ");
        FILE *arquivo;
        arquivo = fopen ("CONSULTORIO_MEDICO.xml", "w");
        if (arquivo == NULL) {
           printf ("Houve um erro ao abrir o arquivo.\n");
        }
        fprintf(arquivo, "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n");
        fprintf(arquivo, "<CONSULTORIO_MEDICO.xml>\n");
        fprintf(arquivo, "<ED-1>\n");
        fprintf(arquivo, "<tema>\n");
        fprintf(arquivo, "CONSULTORIO MEDICO\n");
        fprintf(arquivo, "</tema>\n");
        fprintf(arquivo, "<titulo>\n");
        fprintf(arquivo, "CONSULTORIO MEDICO\n");
        fprintf(arquivo, "</titulo>\n");
        fprintf(arquivo, "<texto>\n");
        fprintf(arquivo, "<linha1>Definicao:</linha1>\n");
        fprintf(arquivo, "<linha2>Sala isolada destinada a prestacaoo de assistencia medica ou odontologica ou de outros profissionais de saude</linha2>\n");
        fprintf(arquivo, "<linha3>de nivel superior.</linha3>\n");
        fprintf(arquivo, "<linha4>--------------------------------------------------------------------------------------------------------------</linha4>\n");
        fprintf(arquivo, "<linha5>Fonte: http://tabnet.datasus.gov.br/cgi/cnes/tipo_estabelecimento.htm</linha5>\n");
        fprintf(arquivo, "</texto>\n");
        fprintf(arquivo, "</ED-1>\n");
        fprintf(arquivo, "<ED-2>\n");
        fprintf(arquivo, "</ED-2>\n");
        fprintf(arquivo, "<ED-3>\n");
        fprintf(arquivo, "<tabela>\n");
        fprintf(arquivo, "<titulo>Tabela TUSS - TERMINOLOGIA UNIFICADA DA SAUDE SUPLEMENTAR</titulo>\n");
        fprintf(arquivo, "<subtabela>\n");
        fprintf(arquivo, "<subtitulo>PROCEDIMENTOS CLINICOS (AMBULATORIAIS)-REABILITACOES-SESSOES</subtitulo>\n");
        fprintf(arquivo, "<item><codigo>20103018</codigo><descricao>Adaptacao e treinamento de recursos opticos para visao subnormal (por sessao) - binocular</descricao><novo_valor>13.41</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103026</codigo><descricao>Amputacao bilateral (preparacao do coto)</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103034</codigo><descricao>Amputacao bilateral (treinamento protetico)</descricao><novo_valor>9.89</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103042</codigo><descricao>Amputacao unilateral (preparacao do coto)</descricao><novo_valor>5.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103050</codigo><descricao>Amputacao unilateral (treinamento protetico)</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103069</codigo><descricao>Assistencia fisiatrica respiratoria em pre e pos-operatorio de condicoes cirurgicas</descricao><novo_valor>4.95</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>4</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103077</codigo><descricao>Ataxias</descricao><novo_valor>4.62</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103093</codigo><descricao>Atendimento fisiatrico no pre e pos-operatorio de pacientes para prevencao de sequelas</descricao><novo_valor>5.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103107</codigo><descricao>Atendimento fisiatrico no pre e pos-parto</descricao><novo_valor>5.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103131</codigo><descricao>Biofeedback com EMG</descricao><novo_valor>16.49</novo_valor><valor_custo>2.1</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103140</codigo><descricao>Bloqueio fenolico, alcoolico ou com toxina botulinica (de pontos motores) - por membro ou segmento corporal</descricao><novo_valor>28.86</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>3</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103158</codigo><descricao>Confeccao de orteses em material termo-sensivel (por unidade)</descricao><novo_valor>7.8</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103166</codigo><descricao>Confeccao de protese imediata</descricao><novo_valor>49.47</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>4</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103174</codigo><descricao>Confeccao de protese provisoria</descricao><novo_valor>41.22</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103182</codigo><descricao>Desvios posturais da coluna vertebral</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103190</codigo><descricao>Disfuncao vesico-uretral</descricao><novo_valor>11.54</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103204</codigo><descricao>Distrofia simpatico-reflexa</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103212</codigo><descricao>Disturbios circulatorios arterio-venosos e linfaticos</descricao><novo_valor>4.62</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103220</codigo><descricao>Doencas pulmonares atendidas em ambulatorio</descricao><novo_valor>5.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103239</codigo><descricao>Exercicios de ortoptica (por sessao)</descricao><novo_valor>8.62</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103247</codigo><descricao>Exercicios para reabilitacao do asmatico (ERAC) - por sessao coletiva</descricao><novo_valor>4.36</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103255</codigo><descricao>Exercicios para reabilitacao do asmatico (ERAI) - por sessao individual</descricao><novo_valor>8.73</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>3.2</valor_auxiliar><porte>1</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103263</codigo><descricao>Hemiparesia</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>3</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103271</codigo><descricao>Hemiplegia</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103280</codigo><descricao>Hemiplegia e hemiparesia com afasia</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103298</codigo><descricao>Hipo ou agenesia de membros</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.7</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103301</codigo><descricao>Infiltracao de ponto gatilho (por musculo) ou agulhamento seco (por musculo)</descricao><novo_valor>27.43</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.1</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103310</codigo><descricao>Lesao nervosa periferica afetando mais de um nervo com alteracoes sensitivas e/ou motoras</descricao><novo_valor>5.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103328</codigo><descricao>Lesao nervosa periferica afetando um nervo com alteracoes sensitivas e/ou motoras</descricao><novo_valor>4.12</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.3</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103344</codigo><descricao>Miopatias</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103360</codigo><descricao>Paciente com D.P.O.C. em atendimento ambulatorial necessitando reeducacao e reabilitacao respiratoria</descricao><novo_valor>5.28</novo_valor><valor_custo>2.5</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103379</codigo><descricao>Paciente em pos-operatorio de cirurgia cardiaca, atendido em ambulatorio, duas a tres vezes por semana</descricao><novo_valor>4.95</novo_valor><valor_custo>1.95</valor_custo><valor_auxiliar>2.5</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103387</codigo><descricao>Pacientes com doenca isquemica do coracao, atendido em ambulatorio de 8 a 24 semanas</descricao><novo_valor>4.95</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103395</codigo><descricao>Pacientes com doenca isquemica do coracao, atendido em ambulatorio, ate 8 semanas de programa</descricao><novo_valor>5.77</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.5</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103409</codigo><descricao>Pacientes com doencas neuro-musculo-esqueleticas com envolvimento tegumentar</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.95</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103417</codigo><descricao>Pacientes sem doenca coronariana clinicamente manifesta, mas considerada de alto  risco,  atendido  em ambulatorio, duas a tres vezes por semana</descricao><novo_valor>3.3</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103425</codigo><descricao>Paralisia cerebral</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103433</codigo><descricao>Paralisia cerebral com disturbio de comunicacao</descricao><novo_valor>9.89</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103441</codigo><descricao>Paraparesia/tetraparesia</descricao><novo_valor>9.89</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2</valor_auxiliar><porte>3</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103450</codigo><descricao>Paraplegia e tetraplegia</descricao><novo_valor>9.89</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103468</codigo><descricao>Parkinson</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103476</codigo><descricao>Patologia neurologica com dependencia de atividades da vida diaria</descricao><novo_valor>11.54</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103484</codigo><descricao>Patologia osteomioarticular em um membro</descricao><novo_valor>4.62</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103492</codigo><descricao>Patologia osteomioarticular em dois ou mais membros</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103506</codigo><descricao>Patologia osteomioarticular em um segmento da coluna</descricao><novo_valor>4.62</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103514</codigo><descricao>Patologia osteomioarticular em diferentes segmentos da coluna</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103522</codigo><descricao>Patologias osteomioarticulares com dependencia de atividades da vida diaria</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.01</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103530</codigo><descricao>Recuperacao funcional pos-operatoria ou por imobilizacao da patologia vertebral</descricao><novo_valor>7.42</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103565</codigo><descricao>Processos inflamatorios pelvicos</descricao><novo_valor>2.47</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>7</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103611</codigo><descricao>Queimados - seguimento ambulatorial para prevencao de sequelas (por segmento)</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103620</codigo><descricao>Reabilitacao de paciente com endoprotese</descricao><novo_valor>9.27</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>3</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103638</codigo><descricao>Reabilitacao labirintica (por sessao)</descricao><novo_valor>13.34</novo_valor><valor_custo>2.43</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103646</codigo><descricao>Reabilitacao perineal com biofeedback</descricao><novo_valor>16.49</novo_valor><valor_custo>2.430</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103654</codigo><descricao>Recuperacao funcional de disturbios crânio-faciais</descricao><novo_valor>4.62</novo_valor><valor_custo>3.21</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103662</codigo><descricao>Recuperacao funcional pos-operatoria ou pos-imobilizacao gessada de  patologia  osteomioarticular  com complicacoes neurovasculares afetando um membro</descricao><novo_valor>7.42</novo_valor><valor_custo>3.2</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103670</codigo><descricao>Recuperacao funcional pos-operatoria ou pos-imobilizacao gessada de  patologia  osteomioarticular  com complicacoes neurovasculares afetando mais de um membro</descricao><novo_valor>9.07</novo_valor><valor_custo>3.3</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103689</codigo><descricao>Retardo do desenvolvimento psicomotor</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103697</codigo><descricao>Sequelas de traumatismos toracicos e abdominais</descricao><novo_valor>4.62</novo_valor><valor_custo>2.67</valor_custo><valor_auxiliar>1.1</valor_auxiliar><porte>6</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103700</codigo><descricao>Sequelas em politraumatizados (em diferentes segmentos)</descricao><novo_valor>9.07</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103719</codigo><descricao>Sinusites</descricao><novo_valor>2.47</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103727</codigo><descricao>Reabilitacao  cardiaca supervisionada. Programa de 12 semanas. Duas a tres sessoes por semana (por sessao)</descricao><novo_valor>3.3</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "</subtabela>\n");
        fprintf(arquivo, "<subtabela>\n");
        fprintf(arquivo, "<subtitulo>PROCEDIMENTOS CLINICOS (AMBULATORIAIS) - TERAPEUTICA</subtitulo>\n");
        fprintf(arquivo, "<item><codigo>20104014</codigo><descricao>Actinoterapia (por sessao)</descricao><novo_valor>9.78</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104022</codigo><descricao>Aplicacao de hipossensibilizante - em consultorio (AHC) exclusive o alergeno - planejamento tecnico para</descricao><novo_valor>2.97</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104049</codigo><descricao>Cateterismo vesical em retencao urinaria</descricao><novo_valor>24.46</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104057</codigo><descricao>Cauterizacao quimica vesical</descricao><novo_valor>57.8</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104065</codigo><descricao>Cerumen - remocao (bilateral)</descricao><novo_valor>24.94</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104073</codigo><descricao>Crioterapia (grupo de ate 5 lesoes)</descricao><novo_valor>49.9</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104081</codigo><descricao>Curativos em geral com anestesia, exceto queimados</descricao><novo_valor>12.22</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104090</codigo><descricao>Curativo de extremidades de origem vascular</descricao><novo_valor>39.12</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104103</codigo><descricao>Curativos em geral sem anestesia, exceto queimados</descricao><novo_valor>12.22</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104111</codigo><descricao>Dilatacao uretral (sessao)</descricao><novo_valor>44.61</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104120</codigo><descricao>Fototerapia com UVA (PUVA) (por sessao)</descricao><novo_valor>24.46</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104138</codigo><descricao>Imunoterapia especifica - 30 dias - planejamento tecnico</descricao><novo_valor>60.33</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>3</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104146</codigo><descricao>Imunoterapia inespecifica - 30 dias - planejamento tecnico</descricao><novo_valor>60.33</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0.54</valor_auxiliar><porte>4</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104154</codigo><descricao>Instilacao vesical ou uretral</descricao><novo_valor>24.46</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104189</codigo><descricao>Sessao de oxigenoterapia hiperbarica (por sessao de 2 horas)</descricao><novo_valor>245</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104200</codigo><descricao>Sessao de psicoterapia de grupo (por paciente)</descricao><novo_valor>11.52</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>4</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>4</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104227</codigo><descricao>Sessao de psicoterapia infantil</descricao><novo_valor>38.03</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.1</valor_auxiliar><porte>1</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104235</codigo><descricao>Terapia inalatoria - por nebulizacao</descricao><novo_valor>6.12</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104243</codigo><descricao>Terapia oncologica com altas doses - planejamento e 1º dia de tratamento</descricao><novo_valor>120.65</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>3.4</valor_auxiliar><porte>3</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104251</codigo><descricao>Terapia oncologica com altas doses - por dia subsequente de tratamento</descricao><novo_valor>19.31</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104260</codigo><descricao>Terapia oncologica com aplicacao de medicamentos por via intracavitaria ou intratecal  - por procedimento</descricao><novo_valor>65.15</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>1.4</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104278</codigo><descricao>Terapia oncologica com aplicacao intra-arterial ou intravenosa de medicamentos em infusao de duracao minima de 6 horas - planejamento e 1º dia de tratamento</descricao><novo_valor>120.65</novo_valor><valor_custo>2.4</valor_custo><valor_auxiliar>1.1</valor_auxiliar><porte>5</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104286</codigo><descricao>Terapia oncologica com aplicacao intra-arterial ou intravenosa de medicamentos em infusao de duracao minima de 6 horas - por dia subsequente de tratamento</descricao><novo_valor>19.31</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>6</porte><filme>4</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104294</codigo><descricao>Terapia oncologica - planejamento e 1º dia de tratamento</descricao><novo_valor>78.18</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>4</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104308</codigo><descricao>Terapia oncologica - por dia subsequente de tratamento</descricao><novo_valor>14.41</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.4</valor_auxiliar><porte>4</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104316</codigo><descricao>Curativo de ouvido (cada)</descricao><novo_valor>14.66</novo_valor><valor_custo>2.1</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104324</codigo><descricao>Curativo oftalmologico</descricao><novo_valor>12.22</novo_valor><valor_custo>2.2</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104383</codigo><descricao>Pulsoterapia / terapia imunologica intravenosa (por sessao) - ambulatorial</descricao><novo_valor>138.39</novo_valor><valor_custo>98.3</valor_custo><valor_auxiliar>93.2</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "</subtabela>\n");
        fprintf(arquivo, "</tabela>\n");
        fprintf(arquivo, "</ED-3>\n");
        fprintf(arquivo, "<ED-4>\n");
        fprintf(arquivo, "</ED-4>\n");
        fprintf(arquivo, "<ED-5>\n");
                fprintf(arquivo, "<tabela>\n");
        fprintf(arquivo, "<titulo>Tabela TUSS - TERMINOLOGIA UNIFICADA DA SAUDE SUPLEMENTAR</titulo>\n");
        fprintf(arquivo, "<subtabela>\n");
        fprintf(arquivo, "<subtitulo>PROCEDIMENTOS CLINICOS (AMBULATORIAIS)-REABILITACOES-SESSOES</subtitulo>\n");
        fprintf(arquivo, "<item><codigo>20103018</codigo><descricao>Adaptacao e treinamento de recursos opticos para visao subnormal (por sessao) - binocular</descricao><novo_valor>13.41</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103026</codigo><descricao>Amputacao bilateral (preparacao do coto)</descricao><novo_valor>8.24</novo_valor><valor_custo>2.5</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103034</codigo><descricao>Amputacao bilateral (treinamento protetico)</descricao><novo_valor>9.89</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103042</codigo><descricao>Amputacao unilateral (preparacao do coto)</descricao><novo_valor>5.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103050</codigo><descricao>Amputacao unilateral (treinamento protetico)</descricao><novo_valor>8.24</novo_valor><valor_custo>2.5</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103069</codigo><descricao>Assistencia fisiatrica respiratoria em pre e pos-operatorio de condicoes cirurgicas</descricao><novo_valor>4.95</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>4</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103077</codigo><descricao>Ataxias</descricao><novo_valor>4.62</novo_valor><valor_custo>1.2</valor_custo><valor_auxiliar>3.2</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103093</codigo><descricao>Atendimento fisiatrico no pre e pos-operatorio de pacientes para prevencao de sequelas</descricao><novo_valor>5.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103107</codigo><descricao>Atendimento fisiatrico no pre e pos-parto</descricao><novo_valor>5.28</novo_valor><valor_custo>2.3</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103131</codigo><descricao>Biofeedback com EMG</descricao><novo_valor>16.49</novo_valor><valor_custo>2.1</valor_custo><valor_auxiliar>3.2</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103140</codigo><descricao>Bloqueio fenolico, alcoolico ou com toxina botulinica (de pontos motores) - por membro ou segmento corporal</descricao><novo_valor>28.86</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>3</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103158</codigo><descricao>Confeccao de orteses em material termo-sensivel (por unidade)</descricao><novo_valor>7.8</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103166</codigo><descricao>Confeccao de protese imediata</descricao><novo_valor>49.47</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>4</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103174</codigo><descricao>Confeccao de protese provisoria</descricao><novo_valor>41.22</novo_valor><valor_custo>3.2</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103182</codigo><descricao>Desvios posturais da coluna vertebral</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103190</codigo><descricao>Disfuncao vesico-uretral</descricao><novo_valor>11.54</novo_valor><valor_custo>5.4</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103204</codigo><descricao>Distrofia simpatico-reflexa</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103212</codigo><descricao>Disturbios circulatorios arterio-venosos e linfaticos</descricao><novo_valor>4.62</novo_valor><valor_custo>5.3</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103220</codigo><descricao>Doencas pulmonares atendidas em ambulatorio</descricao><novo_valor>5.28</novo_valor><valor_custo>2.3</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103239</codigo><descricao>Exercicios de ortoptica (por sessao)</descricao><novo_valor>8.62</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103247</codigo><descricao>Exercicios para reabilitacao do asmatico (ERAC) - por sessao coletiva</descricao><novo_valor>4.36</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103255</codigo><descricao>Exercicios para reabilitacao do asmatico (ERAI) - por sessao individual</descricao><novo_valor>8.73</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>3.2</valor_auxiliar><porte>1</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103263</codigo><descricao>Hemiparesia</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>6.4</valor_auxiliar><porte>3</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103271</codigo><descricao>Hemiplegia</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103280</codigo><descricao>Hemiplegia e hemiparesia com afasia</descricao><novo_valor>6.6</novo_valor><valor_custo>4.8</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103298</codigo><descricao>Hipo ou agenesia de membros</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.7</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103301</codigo><descricao>Infiltracao de ponto gatilho (por musculo) ou agulhamento seco (por musculo)</descricao><novo_valor>27.43</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.1</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103310</codigo><descricao>Lesao nervosa periferica afetando mais de um nervo com alteracoes sensitivas e/ou motoras</descricao><novo_valor>5.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103328</codigo><descricao>Lesao nervosa periferica afetando um nervo com alteracoes sensitivas e/ou motoras</descricao><novo_valor>4.12</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.3</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103344</codigo><descricao>Miopatias</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>6.5</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103360</codigo><descricao>Paciente com D.P.O.C. em atendimento ambulatorial necessitando reeducacao e reabilitacao respiratoria</descricao><novo_valor>5.28</novo_valor><valor_custo>2.5</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103379</codigo><descricao>Paciente em pos-operatorio de cirurgia cardiaca, atendido em ambulatorio, duas a tres vezes por semana</descricao><novo_valor>4.95</novo_valor><valor_custo>1.95</valor_custo><valor_auxiliar>2.5</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103387</codigo><descricao>Pacientes com doenca isquemica do coracao, atendido em ambulatorio de 8 a 24 semanas</descricao><novo_valor>4.95</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103395</codigo><descricao>Pacientes com doenca isquemica do coracao, atendido em ambulatorio, ate 8 semanas de programa</descricao><novo_valor>5.77</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.5</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103409</codigo><descricao>Pacientes com doencas neuro-musculo-esqueleticas com envolvimento tegumentar</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.95</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103417</codigo><descricao>Pacientes sem doenca coronariana clinicamente manifesta, mas considerada de alto  risco,  atendido  em ambulatorio, duas a tres vezes por semana</descricao><novo_valor>3.3</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103425</codigo><descricao>Paralisia cerebral</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>6.5</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103433</codigo><descricao>Paralisia cerebral com disturbio de comunicacao</descricao><novo_valor>9.89</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103441</codigo><descricao>Paraparesia/tetraparesia</descricao><novo_valor>9.89</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2</valor_auxiliar><porte>3</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103450</codigo><descricao>Paraplegia e tetraplegia</descricao><novo_valor>9.89</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103468</codigo><descricao>Parkinson</descricao><novo_valor>6.6</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103476</codigo><descricao>Patologia neurologica com dependencia de atividades da vida diaria</descricao><novo_valor>11.54</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103484</codigo><descricao>Patologia osteomioarticular em um membro</descricao><novo_valor>4.62</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103492</codigo><descricao>Patologia osteomioarticular em dois ou mais membros</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103506</codigo><descricao>Patologia osteomioarticular em um segmento da coluna</descricao><novo_valor>4.62</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103514</codigo><descricao>Patologia osteomioarticular em diferentes segmentos da coluna</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103522</codigo><descricao>Patologias osteomioarticulares com dependencia de atividades da vida diaria</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.01</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103530</codigo><descricao>Recuperacao funcional pos-operatoria ou por imobilizacao da patologia vertebral</descricao><novo_valor>7.42</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103565</codigo><descricao>Processos inflamatorios pelvicos</descricao><novo_valor>2.47</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>7</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103611</codigo><descricao>Queimados - seguimento ambulatorial para prevencao de sequelas (por segmento)</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103620</codigo><descricao>Reabilitacao de paciente com endoprotese</descricao><novo_valor>9.27</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>3</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103638</codigo><descricao>Reabilitacao labirintica (por sessao)</descricao><novo_valor>13.34</novo_valor><valor_custo>2.43</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103646</codigo><descricao>Reabilitacao perineal com biofeedback</descricao><novo_valor>16.49</novo_valor><valor_custo>2.430</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103654</codigo><descricao>Recuperacao funcional de disturbios crânio-faciais</descricao><novo_valor>4.62</novo_valor><valor_custo>3.21</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103662</codigo><descricao>Recuperacao funcional pos-operatoria ou pos-imobilizacao gessada de  patologia  osteomioarticular  com complicacoes neurovasculares afetando um membro</descricao><novo_valor>7.42</novo_valor><valor_custo>3.2</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103670</codigo><descricao>Recuperacao funcional pos-operatoria ou pos-imobilizacao gessada de  patologia  osteomioarticular  com complicacoes neurovasculares afetando mais de um membro</descricao><novo_valor>9.07</novo_valor><valor_custo>3.3</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103689</codigo><descricao>Retardo do desenvolvimento psicomotor</descricao><novo_valor>8.24</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103697</codigo><descricao>Sequelas de traumatismos toracicos e abdominais</descricao><novo_valor>4.62</novo_valor><valor_custo>2.67</valor_custo><valor_auxiliar>1.1</valor_auxiliar><porte>6</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103700</codigo><descricao>Sequelas em politraumatizados (em diferentes segmentos)</descricao><novo_valor>9.07</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103719</codigo><descricao>Sinusites</descricao><novo_valor>2.47</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20103727</codigo><descricao>Reabilitacao  cardiaca supervisionada. Programa de 12 semanas. Duas a tres sessoes por semana (por sessao)</descricao><novo_valor>3.3</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "</subtabela>\n");
        fprintf(arquivo, "<subtabela>\n");
        fprintf(arquivo, "<subtitulo>PROCEDIMENTOS CLINICOS (AMBULATORIAIS) - TERAPEUTICA</subtitulo>\n");
        fprintf(arquivo, "<item><codigo>20104014</codigo><descricao>Actinoterapia (por sessao)</descricao><novo_valor>9.78</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104022</codigo><descricao>Aplicacao de hipossensibilizante - em consultorio (AHC) exclusive o alergeno - planejamento tecnico para</descricao><novo_valor>2.97</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104049</codigo><descricao>Cateterismo vesical em retencao urinaria</descricao><novo_valor>24.46</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104057</codigo><descricao>Cauterizacao quimica vesical</descricao><novo_valor>57.8</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104065</codigo><descricao>Cerumen - remocao (bilateral)</descricao><novo_valor>24.94</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104073</codigo><descricao>Crioterapia (grupo de ate 5 lesoes)</descricao><novo_valor>49.9</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104081</codigo><descricao>Curativos em geral com anestesia, exceto queimados</descricao><novo_valor>12.22</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104090</codigo><descricao>Curativo de extremidades de origem vascular</descricao><novo_valor>39.12</novo_valor><valor_custo>2.3</valor_custo><valor_auxiliar>1.2</valor_auxiliar><porte>2</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104103</codigo><descricao>Curativos em geral sem anestesia, exceto queimados</descricao><novo_valor>12.22</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104111</codigo><descricao>Dilatacao uretral (sessao)</descricao><novo_valor>44.61</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>1</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104120</codigo><descricao>Fototerapia com UVA (PUVA) (por sessao)</descricao><novo_valor>24.46</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104138</codigo><descricao>Imunoterapia especifica - 30 dias - planejamento tecnico</descricao><novo_valor>60.33</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>3</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104146</codigo><descricao>Imunoterapia inespecifica - 30 dias - planejamento tecnico</descricao><novo_valor>60.33</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0.54</valor_auxiliar><porte>4</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104154</codigo><descricao>Instilacao vesical ou uretral</descricao><novo_valor>24.46</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104189</codigo><descricao>Sessao de oxigenoterapia hiperbarica (por sessao de 2 horas)</descricao><novo_valor>245</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104200</codigo><descricao>Sessao de psicoterapia de grupo (por paciente)</descricao><novo_valor>11.52</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>4</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>4</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104227</codigo><descricao>Sessao de psicoterapia infantil</descricao><novo_valor>38.03</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.1</valor_auxiliar><porte>1</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104235</codigo><descricao>Terapia inalatoria - por nebulizacao</descricao><novo_valor>6.12</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104243</codigo><descricao>Terapia oncologica com altas doses - planejamento e 1º dia de tratamento</descricao><novo_valor>120.65</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>3.4</valor_auxiliar><porte>3</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104251</codigo><descricao>Terapia oncologica com altas doses - por dia subsequente de tratamento</descricao><novo_valor>19.31</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104260</codigo><descricao>Terapia oncologica com aplicacao de medicamentos por via intracavitaria ou intratecal  - por procedimento</descricao><novo_valor>65.15</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>1.4</valor_auxiliar><porte>5</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104278</codigo><descricao>Terapia oncologica com aplicacao intra-arterial ou intravenosa de medicamentos em infusao de duracao minima de 6 horas - planejamento e 1º dia de tratamento</descricao><novo_valor>120.65</novo_valor><valor_custo>2.4</valor_custo><valor_auxiliar>1.1</valor_auxiliar><porte>5</porte><filme>2</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104286</codigo><descricao>Terapia oncologica com aplicacao intra-arterial ou intravenosa de medicamentos em infusao de duracao minima de 6 horas - por dia subsequente de tratamento</descricao><novo_valor>19.31</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>6</porte><filme>4</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104294</codigo><descricao>Terapia oncologica - planejamento e 1º dia de tratamento</descricao><novo_valor>78.18</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>4</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104308</codigo><descricao>Terapia oncologica - por dia subsequente de tratamento</descricao><novo_valor>14.41</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>2.4</valor_auxiliar><porte>4</porte><filme>0</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104316</codigo><descricao>Curativo de ouvido (cada)</descricao><novo_valor>14.66</novo_valor><valor_custo>2.1</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>0</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104324</codigo><descricao>Curativo oftalmologico</descricao><novo_valor>12.22</novo_valor><valor_custo>2.2</valor_custo><valor_auxiliar>0</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "<item><codigo>20104383</codigo><descricao>Pulsoterapia / terapia imunologica intravenosa (por sessao) - ambulatorial</descricao><novo_valor>138.39</novo_valor><valor_custo>98.3</valor_custo><valor_auxiliar>93.2</valor_auxiliar><porte>2</porte><filme>1</filme></item>\n");
        fprintf(arquivo, "</subtabela>\n");
        fprintf(arquivo, "</tabela>\n");
        fprintf(arquivo, "</ED-5>\n");
        fprintf(arquivo, "<ED-6>\n");
        fprintf(arquivo, "</ED-6>\n");
        fprintf(arquivo, "<ED-7>\n");
        fprintf(arquivo, "<tabela_consulta_medica>\n");
        fprintf(arquivo, "<consulta><numero_consulta>31</numero_consulta><nome_paciente>Ana Maria Pereira da Costa</nome_paciente><data><dia>1</dia><mes>2</mes><ano>2015</ano></data><item><codigo>20104316</codigo><descricao>Curativo de ouvido (cada)</descricao><novo_valor>44.66</novo_valor><valor_custo>21.1</valor_custo><valor_auxiliar>12.1</valor_auxiliar><porte>0</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>82</numero_consulta><nome_paciente>Vicente Silva Godoy</nome_paciente><data><dia>3</dia><mes>2</mes><ano>2015</ano></data><item><codigo>20103697</codigo><descricao>Sequelas de traumatismos toracicos e abdominais</descricao><novo_valor>44.62</novo_valor><valor_custo>22.67</valor_custo><valor_auxiliar>11.1</valor_auxiliar><porte>6</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>104</numero_consulta><nome_paciente>Antonio Carlos Cardoso Duarte</nome_paciente><data><dia>5</dia><mes>2</mes><ano>2015</ano></data><item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>28.9</valor_custo><valor_auxiliar>11.0</valor_auxiliar><porte>4</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>127</numero_consulta><nome_paciente>Cristiano Marinho Figueira</nome_paciente><data><dia>29</dia><mes>3</mes><ano>2015</ano></data><item><codigo>20103697</codigo><descricao>Sequelas de traumatismos toracicos e abdominais</descricao><novo_valor>44.62</novo_valor><valor_custo>2.67</valor_custo><valor_auxiliar>11.1</valor_auxiliar><porte>6</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>182</numero_consulta><nome_paciente>Carolina Ferreira de Melo</nome_paciente><data><dia>12</dia><mes>4</mes><ano>2015</ano></data><item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>12</valor_auxiliar><porte>4</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>265</numero_consulta><nome_paciente>Lucia Maria Calixto Paes</nome_paciente><data><dia>23</dia><mes>4</mes><ano>2015</ano></data><item><codigo>20104316</codigo><descricao>Curativo de ouvido (cada)</descricao><novo_valor>44.66</novo_valor><valor_custo>2.1</valor_custo><valor_auxiliar>11.1</valor_auxiliar><porte>0</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>312</numero_consulta><nome_paciente>Lucimara Cavalcante Dias</nome_paciente><data><dia>8</dia><mes>6</mes><ano>2015</ano></data><item><codigo>20103093</codigo><descricao>Atendimento fisiatrico no pre e pos-operatorio de pacientes para prevencao de sequelas</descricao><novo_valor>55.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>5</valor_auxiliar><porte>2</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>377</numero_consulta><nome_paciente>Amauri Santos Junior</nome_paciente><data><dia>25</dia><mes>8</mes><ano>2015</ano></data><item><codigo>20104090</codigo><descricao>Curativo de extremidades de origem vascular</descricao><novo_valor>39.12</novo_valor><valor_custo>2.3</valor_custo><valor_auxiliar>11.2</valor_auxiliar><porte>2</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>432</numero_consulta><nome_paciente>Juliana da Costa Silva</nome_paciente><data><dia>17</dia><mes>9</mes><ano>2015</ano></data><item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>1</valor_auxiliar><porte>4</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>486</numero_consulta><nome_paciente>Bernadete Figueira de Moura</nome_paciente><data><dia>20</dia><mes>9</mes><ano>2015</ano></data><item><codigo>20104090</codigo><descricao>Curativo de extremidades de origem vascular</descricao><novo_valor>49.12</novo_valor><valor_custo>12.3</valor_custo><valor_auxiliar>11.2</valor_auxiliar><porte>2</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>502</numero_consulta><nome_paciente>Antonio Jose Garcia das Chagas</nome_paciente><data><dia>6</dia><mes>10</mes><ano>2015</ano></data><item><codigo>20103093</codigo><descricao>Atendimento fisiatrico no pre e pos-operatorio de pacientes para prevencao de sequelas</descricao><novo_valor>35.28</novo_valor><valor_custo>21.17</valor_custo><valor_auxiliar>13</valor_auxiliar><porte>2</porte><filme>1</filme></item></consulta>\n");
		fprintf(arquivo, "</tabela_consulta_medica>\n");
        fprintf(arquivo, "</ED-7>\n");
        fprintf(arquivo, "<ED-8>\n");
        fprintf(arquivo, "</ED-8>\n");
        fprintf(arquivo, "<ED-9>\n");
        fprintf(arquivo, "</ED-9>\n");
        fprintf(arquivo, "<ED-10>\n");
        fprintf(arquivo, "</ED-10>\n");
        fprintf(arquivo, "<ED-11>\n");
        fprintf(arquivo, "</ED-11>\n");
        fprintf(arquivo, "<ED-12>\n");
        fprintf(arquivo, "<tabela_consulta_medica>\n");
        fprintf(arquivo, "<consulta><numero_consulta>31</numero_consulta><nome_paciente>Ana Maria Pereira da Costa</nome_paciente><data><dia>1</dia><mes>2</mes><ano>2015</ano></data><item><codigo>20104316</codigo><descricao>Curativo de ouvido (cada)</descricao><novo_valor>44.66</novo_valor><valor_custo>21.1</valor_custo><valor_auxiliar>12.1</valor_auxiliar><porte>0</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>82</numero_consulta><nome_paciente>Vicente Silva Godoy</nome_paciente><data><dia>3</dia><mes>2</mes><ano>2015</ano></data><item><codigo>20103697</codigo><descricao>Sequelas de traumatismos toracicos e abdominais</descricao><novo_valor>44.62</novo_valor><valor_custo>22.67</valor_custo><valor_auxiliar>11.1</valor_auxiliar><porte>6</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>104</numero_consulta><nome_paciente>Antonio Carlos Cardoso Duarte</nome_paciente><data><dia>5</dia><mes>2</mes><ano>2015</ano></data><item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>28.9</valor_custo><valor_auxiliar>11.0</valor_auxiliar><porte>4</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>127</numero_consulta><nome_paciente>Cristiano Marinho Figueira</nome_paciente><data><dia>29</dia><mes>3</mes><ano>2015</ano></data><item><codigo>20103697</codigo><descricao>Sequelas de traumatismos toracicos e abdominais</descricao><novo_valor>44.62</novo_valor><valor_custo>2.67</valor_custo><valor_auxiliar>11.1</valor_auxiliar><porte>6</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>182</numero_consulta><nome_paciente>Carolina Ferreira de Melo</nome_paciente><data><dia>12</dia><mes>4</mes><ano>2015</ano></data><item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>12</valor_auxiliar><porte>4</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>265</numero_consulta><nome_paciente>Lucia Maria Calixto Paes</nome_paciente><data><dia>23</dia><mes>4</mes><ano>2015</ano></data><item><codigo>20104316</codigo><descricao>Curativo de ouvido (cada)</descricao><novo_valor>44.66</novo_valor><valor_custo>2.1</valor_custo><valor_auxiliar>11.1</valor_auxiliar><porte>0</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>312</numero_consulta><nome_paciente>Lucimara Cavalcante Dias</nome_paciente><data><dia>8</dia><mes>6</mes><ano>2015</ano></data><item><codigo>20103093</codigo><descricao>Atendimento fisiatrico no pre e pos-operatorio de pacientes para prevencao de sequelas</descricao><novo_valor>55.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>5</valor_auxiliar><porte>2</porte><filme>1</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>377</numero_consulta><nome_paciente>Amauri Santos Junior</nome_paciente><data><dia>25</dia><mes>8</mes><ano>2015</ano></data><item><codigo>20104090</codigo><descricao>Curativo de extremidades de origem vascular</descricao><novo_valor>39.12</novo_valor><valor_custo>2.3</valor_custo><valor_auxiliar>11.2</valor_auxiliar><porte>2</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>432</numero_consulta><nome_paciente>Juliana da Costa Silva</nome_paciente><data><dia>17</dia><mes>9</mes><ano>2015</ano></data><item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>1</valor_auxiliar><porte>4</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>486</numero_consulta><nome_paciente>Bernadete Figueira de Moura</nome_paciente><data><dia>20</dia><mes>9</mes><ano>2015</ano></data><item><codigo>20104090</codigo><descricao>Curativo de extremidades de origem vascular</descricao><novo_valor>49.12</novo_valor><valor_custo>12.3</valor_custo><valor_auxiliar>11.2</valor_auxiliar><porte>2</porte><filme>0</filme></item></consulta>\n");
        fprintf(arquivo, "<consulta><numero_consulta>502</numero_consulta><nome_paciente>Antonio Jose Garcia das Chagas</nome_paciente><data><dia>6</dia><mes>10</mes><ano>2015</ano></data><item><codigo>20103093</codigo><descricao>Atendimento fisiatrico no pre e pos-operatorio de pacientes para prevencao de sequelas</descricao><novo_valor>35.28</novo_valor><valor_custo>21.17</valor_custo><valor_auxiliar>13</valor_auxiliar><porte>2</porte><filme>1</filme></item></consulta>\n");
		fprintf(arquivo, "<consulta><numero_consulta>545</numero_consulta><nome_paciente>Gustavo de Andrade Souza</nome_paciente><data><dia>12</dia><mes>11</mes><ano>2015</ano></data><item><codigo>20104316</codigo><descricao>Curativo de ouvido (cada)</descricao><novo_valor>44.66</novo_valor><valor_custo>2.1</valor_custo><valor_auxiliar>11.1</valor_auxiliar><porte>0</porte><filme>1</filme></item></consulta>\n");
		fprintf(arquivo, "<consulta><numero_consulta>612</numero_consulta><nome_paciente>Jefferson Barreto Falcao</nome_paciente><data><dia>21</dia><mes>12</mes><ano>2015</ano></data><item><codigo>20103697</codigo><descricao>Sequelas de traumatismos toracicos e abdominais</descricao><novo_valor>44.62</novo_valor><valor_custo>22.67</valor_custo><valor_auxiliar>11.1</valor_auxiliar><porte>6</porte><filme>1</filme></item></consulta>\n");
		fprintf(arquivo, "<consulta><numero_consulta>634</numero_consulta><nome_paciente>Leonardo Fernandes Marinho</nome_paciente><data><dia>23</dia><mes>1</mes><ano>2016</ano></data><item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>12</valor_auxiliar><porte>4</porte><filme>0</filme></item></consulta>\n");
		fprintf(arquivo, "<consulta><numero_consulta>677</numero_consulta><nome_paciente>Leandra Inacio de Paula</nome_paciente><data><dia>12</dia><mes>2</mes><ano>2016</ano></data><item><codigo>20103093</codigo><descricao>Atendimento fisiatrico no pre e pos-operatorio de pacientes para prevencao de sequelas</descricao><novo_valor>55.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>5</valor_auxiliar><porte>2</porte><filme>1</filme></item></consulta>\n");
		fprintf(arquivo, "<consulta><numero_consulta>732</numero_consulta><nome_paciente>Ilcimar Neves da Silva</nome_paciente><data><dia>5</dia><mes>4</mes><ano>2016</ano></data><item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>12</valor_auxiliar><porte>4</porte><filme>0</filme></item></consulta>\n");
		fprintf(arquivo, "<consulta><numero_consulta>756</numero_consulta><nome_paciente>Alanna Dutra Barreto</nome_paciente><data><dia>6</dia><mes>5</mes><ano>2016</ano></data><item><codigo>20103093</codigo><descricao>Atendimento fisiatrico no pre e pos-operatorio de pacientes para prevencao de sequelas</descricao><novo_valor>35.28</novo_valor><valor_custo>21.17</valor_custo><valor_auxiliar>13</valor_auxiliar><porte>2</porte><filme>1</filme></item></consulta>\n");
		fprintf(arquivo, "<consulta><numero_consulta>823</numero_consulta><nome_paciente>Jose Francisco Donizete Santana</nome_paciente><data><dia>7</dia><mes>6</mes><ano>2016</ano></data><item><codigo>20103697</codigo><descricao>Sequelas de traumatismos toracicos e abdominais</descricao><novo_valor>44.62</novo_valor><valor_custo>22.67</valor_custo><valor_auxiliar>11.1</valor_auxiliar><porte>6</porte><filme>1</filme></item></consulta>\n");
		fprintf(arquivo, "<consulta><numero_consulta>892</numero_consulta><nome_paciente>Felipe Medeiros Balbino</nome_paciente><data><dia>24</dia><mes>7</mes><ano>2016</ano></data><item><codigo>20104219</codigo><descricao>Sessao de psicoterapia individual</descricao><novo_valor>34.57</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>12</valor_auxiliar><porte>4</porte><filme>0</filme></item></consulta>\n");
		fprintf(arquivo, "<consulta><numero_consulta>931</numero_consulta><nome_paciente>Thiago Silva da Conceicao</nome_paciente><data><dia>12</dia><mes>9</mes><ano>2016</ano></data><item><codigo>20103093</codigo><descricao>Atendimento fisiatrico no pre e pos-operatorio de pacientes para prevencao de sequelas</descricao><novo_valor>55.28</novo_valor><valor_custo>0</valor_custo><valor_auxiliar>5</valor_auxiliar><porte>2</porte><filme>1</filme></item></consulta>\n");
		fprintf(arquivo, "</tabela_consulta_medica>\n");
        fprintf(arquivo, "</ED-12>\n");
        fprintf(arquivo, "<ED-13>\n");
        fprintf(arquivo, "</ED-13>\n");
        fprintf(arquivo, "<ED-14>\n");
        fprintf(arquivo, "</ED-14>\n");
        fprintf(arquivo, "<ED-15>\n");
        fprintf(arquivo, "</ED-15>\n");
        fprintf(arquivo, "<ED-16>\n");
        fprintf(arquivo, "</ED-16>\n");
        fprintf(arquivo, "<ED-17>\n");
        fprintf(arquivo, "</ED-17>\n");
        fprintf(arquivo, "<ED-18>\n");
        fprintf(arquivo, "</ED-18>\n");
        fprintf(arquivo, "<ED-19>\n");
        fprintf(arquivo, "</ED-19>\n");
        fprintf(arquivo, "<ED-20>\n");
        fprintf(arquivo, "</ED-20>\n");
        fprintf(arquivo, "</CONSULTORIO_MEDICO.xml>\n");
        printf ("\n\n\tArquivo CONSULTORIO_MEDICO.xml foi criado com sucesso!\n\n\n");
        fclose (arquivo);
        system("PAUSE");
}
void func_03_01_02_ler_tabela_tuss_xml()
{             
      func_gen_titulo(" Menu Principal->ED-03 Arquivo XML",
                      " ",
                      "                                        LEITURA DINAMICA TABELA TUSS", 31,
                      "     Utilizando a funcao implementada func_gen_ler_tag(), onde o usuario passa a tag do arquivo xml",
                      "                         e a funcao retorna o texto que esta localizado entre as tags");
      int i;
      int resposta;
      int posicao_leitura;
      int posicao_pos_leitura;
      char texto[5001];
      posicao_leitura=71;
      posicao_pos_leitura=0;
      FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
      //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {
            func_gen_limpa_tela();            
            func_03_01_01_escrever_arquivo_xml();
            return;
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<19;i++)//Pula 22 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      //le Titulo da tabela
      func_gen_ler_tag("<titulo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      printf("\nTitulo: %s\n", texto);
      func_gen_linhac();
      //pula duas linhas para ler subtitulo
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      //le subtitulo da tabela
      func_gen_ler_tag("<subtitulo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      printf("\nSubtitulo Tabela 1: %s \n", texto);
      func_gen_linhac();
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      //Lendo dados de 60 itens da tabela
      for(i=0;i<61;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Codigo: %s \n", texto);
          //lendo descricao
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Descricao: %s\n", texto);
          //lendo novo valor
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Novo Valor R$%s\n", texto);
          //lendo valor custo
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Valor_custo: R$%s\n", texto);
          //lendo valor auxiliar
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Valor_auxiliar: R$%s\n", texto);
          //lendo porte
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Porte: %s\n", texto);
          //lendo filme
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Filme: %s\n", texto);
          //gera linha preta   
          func_gen_linhac();
          //le ate a quantidade de bytes ate o final da linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura; 
      }
      
      //LER SUB TABELA 2
      func_gen_linhap();
      //pula duas linhas     
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      //le subtitulo da tabela
      func_gen_ler_tag("<subtitulo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      printf("\nSubtitulo Tabela 2: %s \n", texto);
      func_gen_linhac();
      //pula uma linha
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      for(i=0;i<29;i++)//Lendo alguns dados de 60 itens da tabela
      {
          //lendo codigo
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Codigo: %s \n", texto);
          //lendo descricao
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Descricao: %s\n", texto);
          //lendo novo valor
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Novo Valor R$%s\n", texto);
          //lendo valor custo
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Valor_custo: R$%s\n", texto);
          //lendo valor auxiliar
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Valor_auxiliar: R$%s\n", texto);
          //lendo porte
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Porte: %s\n", texto);
          //lendo filme
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Filme: %s\n", texto);
          //gera linha cinza  
          func_gen_linhac();
          //le ate a quantidade de bytes ate o final da linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura; 
      }
      system("PAUSE");
      return;
}
void func_03_01_03_escrever_arquivo_binario()
{
      func_gen_titulo(" Menu Principal->ED-03 Arquivo XML",
                      " ",
                      "                                            Escrita do arquivo binario", 31,
                      "                                             a partir do arquivo XML.",
                      "                                            Utilizando a Funcao fwrite()");
      //cria uma struct de um item
      struct item{ int codigo;
                   char descricao[5000]; 
                   float novo_valor;
                   float valor_custo;
                   float valor_auxiliar;
                   int porte;
                   int filme;};
      //declarando variaveis de tipos basicos
      int i;
      int resposta;
      int posicao_leitura;
      int posicao_pos_leitura;
      char texto[5001];
      //declarando as structs
      struct item tab1_item[61];
      struct item tab2_item[29];
      //declarando arquivos
      FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
      FILE *arquivo_binario = fopen("CONSULTORIO_MEDICO.bin", "wb");
      //definindo posicao inicial de leitura
      posicao_leitura=71;
      posicao_pos_leitura=0;
      //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {   
            func_gen_limpa_tela();
            func_03_01_01_escrever_arquivo_xml();
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<19;i++)//Pula linhas ate começar ler os dados da tabela
      {   
          //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      //le Titulo da tabela
      func_gen_ler_tag("<titulo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      //atribui titulo da tabela
      func_gen_linhac();
      //pula linhas
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      //le subtitulo da tabela
      func_gen_ler_tag("<subtitulo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      func_gen_linhac();
      //pula linha
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      //le dados
      for(i=0;i<61;i++)//Lendo alguns dados de 60 itens da tabela
      {   
          //lendo dado
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Codigo: %s \n", texto);
          tab1_item[i].codigo=atoi(texto);//converte o codigo lido para int e atribui a struct
          //lendo dado
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Descricao: %s\n", texto);
          strcpy(tab1_item[i].descricao,texto);//copia string scricao para o item  
          //lendo dado
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Novo Valor R$%s\n", texto);
          tab1_item[i].novo_valor=atof(texto);
          //lendo dado
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Valor_custo: R$%s\n", texto);
          tab1_item[i].valor_custo=atof(texto);
          //lendo dado
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Valor_auxiliar: R$%s\n", texto);
          tab1_item[i].valor_auxiliar=atof(texto);
          
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Porte: %s\n", texto);
          tab1_item[i].porte=atoi(texto);
          //lendo dado
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Filme: %s\n", texto);
          tab1_item[i].filme=atoi(texto);
           //lendo dado   
          func_gen_linhac();
          //le ate a quantidade de bytes ate o final da linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;  
      }
      //escrevendo dados da tabela 1 em forma de struct item
      fwrite(tab1_item,sizeof(struct item),61,arquivo_binario);
      //LER SUB TABELA 2
      //pula linhas  
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      //le subtitulo da tabela
      func_gen_ler_tag("<subtitulo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      printf("\nSubtitulo Tabela 2: %s \n", texto);
      //pula linha
      func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
      posicao_leitura = posicao_leitura + posicao_pos_leitura;
      for(i=0;i<29;i++)//Lendo 28 itens da tabela
      {
          //lendo dado
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Codigo: %s \n", texto);
          tab2_item[i].codigo=atoi(texto);//converte o codigo lido para int e atribui a struct
          //lendo dado
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Descricao: %s\n", texto);
          strcpy(tab2_item[i].descricao,texto);//copia string scricao para o item  
          //lendo dado
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Novo Valor R$%s\n", texto);
          tab2_item[i].novo_valor=atof(texto);
          //lendo dado
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Valor_custo: R$%s\n", texto);
          tab2_item[i].valor_custo=atof(texto);
          //lendo dado
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Valor_auxiliar: R$%s\n", texto);
          tab2_item[i].valor_auxiliar=atof(texto);
          //lendo dado
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Porte: %s\n", texto);
          tab2_item[i].porte=atoi(texto);
          //lendo dado
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          printf("Filme: %s\n", texto);
          tab2_item[i].filme=atoi(texto);
          //gera linha cinza
          func_gen_linhac();
          //le ate a quantidade de bytes ate o final da linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura; 
      }
      fwrite(tab2_item,sizeof(struct item),29,arquivo_binario);
      fclose(arquivo_binario);
      system("PAUSE");
      return;
}
void func_03_01_04_TAD()
{     
      func_gen_titulo(" Menu Principal->ED-03 Arquivo XML",
                      " ",
                      "                                                      TAD-03", 31,
                      "                                         ESPECIFICACAO DAS FUNCOES DA TAD-03",
                      " ");                                              
      printf("\n\nNesta atividade, utilizamos os dados da tabela TUSS, onde o codigo e uma variavel do tipo int, a descricao do tipo char, o novo valor e do tipo float, o valor custo e do tipo float, o valor auxiliar e do tipo float, o nivel e do tipo int e o filme e do tipo int. Cada item desse representa uma coluna na tabela tuss. Entao lemos esses itens do arquivo xml e escrevemos em tela.\nNesta atividade, implementamos 4 funcoes listadas abaixo:\n");
      printf("\n\n\t(1)-func_gen_ler_tag()\n");
      printf("\n\t(2)-func_03_01_01_escrever_arquivo_xml()\n");
      printf("\n\t(3)-func_03_01_02_ler_tabela_tuss_xml()\n");
      printf("\n\t(4)-func_03_01_03_escrever_arquivo_binario()\n");
      printf("\n\nA funcao (1), tem como funcionalidade, receber uma tag e retornar o texto contido dentro desta tag contida em um arquivo xml informado tambem na funcao. Esta funcao tambem retorna a quantidade de caracteres lido no arquivo, servindo assim para posicionamentos postertiores com a finalidade de ler novas tags. Quando informada uma tag que nao existe na linha, essa funcao vai ate o final da linha retornando a quantidade de caracteres presentes ate o final da linha. Entao, informamos algumas vezes tags inexistentes como recurso auxiliar para para pular linhas no arquivo xml.\n");
      printf("\n\nA funcao (2) e bem simples. Ela escreve o arquivo xml como especificado na respectiva atividade. lembrando que esse arquivo e escrito com o nome CONSULTORIO_MEDICO.xml.\n");
      printf("\n\nA funcao (3) tem como finalidade ler a tabela tuss do arquivo xml, utilizando a funcao (1) e exibe de forma organizada na tela.\n");
      printf("\n\nA funcao (4) tambem le todo o arquivo xml porem, nao exibe na tela e sim escreve em um arquivo binario. Para escrever o arquivo binario, utilizamos a struct item, onde e composta pelas colunas da tabela. Optamos por utiliazar uma struct ao escrever no arquivo binario por conta de facilitar a leitura e a escrita deste tipo de arquivo. Lembrando que ao ler o arquivo xml, os tados lidos sao do tipo char, dependendo da variavel, tivemos que fazer as devidas conversoes antes de atribuir os valores aos campos da struct item.\n\n\n");
     
	  printf("\n\n\n");
	  
	  printf("\tVariaveis:\n\n");
	  printf("\t(1) char texto[5001]\n");
	  printf("\t(2) struct item{ int codigo;\n");
	  printf("\t                 char descricao[5000]; \n");
	  printf("\t                 float novo_valor;\n");
	  printf("\t                 float valor_custo;\n");
	  printf("\t                 float valor_auxiliar;\n");
	  printf("\t                 int porte;\n");
	  printf("\t                 int filme;};\n");
      printf("\n\n\n");
      printf("-Explicacao Para Variavel (1)\n *Vetor de caracteres de tamanho 5001 responsavel por armazenar a linha lida do arquivo xml na funcao (3). Na funcao (4) esse vetor tambem e resposavel por receber linha a linha do arquivo xml para  auxiliar na escrita do arquivo binario.\n\n");
	  printf("-Explicacao Para Variavel (2)\n *Essa struct modela cada linha das subtabela presentes no aruqivo xml. Cada linha e considerada um item. Como cada linha tem um codigo, uma descricao, um novo valor, um valor custo, um valor auxiliar, um porte e um filme. Essa struct possui esses campos tambem. Na funcao  (4) o dado e lido do arquivo xml e convertido para o respectivo tipo do campo da struct item. Essa struct foi criada para auxiliar na escrita do arquivo binario. Ao consultar diversas literaturas, observou-se que escrever arquivos binarios utilizando structs, torna-se o processo muito pratico, justificando entao, a criacao dessa struct.\n\n\n\n");
	 
	  func_gen_linhap();
      system("PAUSE");
}
void func_04_01_01_visualizar_arquivo_binario()
{
      /*struct item{ int codigo;
                   char descricao[5000]; 
                   float novo_valor;
                   float valor_custo;
                   float valor_auxiliar;
                   int porte;
                   int filme;};*/
      int resposta;
      int i;
      struct item it[90];
      func_gen_titulo(" Menu Principal->ED-04 Arquivo",
                      "                                          Visualizacao de Arquivo Binario",
                      "                                            previamente escrito em disco", 31,
                      "                                         Com o nome: CONSULTORIO_MEDICO.BIN",
                      "                                             utilizando a funcao fread()");                                          
      FILE *arquivo_binario = fopen("CONSULTORIO_MEDICO.bin", "rb");
      //char linha[5001];
      if (!arquivo_binario)//SE NAO, PERGUNTA SE QUER CRIAR
      {
            printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
            func_gen_linhap();
            printf(">");
            scanf("%d", &resposta);
            if (resposta==1)
            {   
                func_gen_limpa_tela();
                func_03_01_03_escrever_arquivo_binario();
                return;
            }
            else//SE SIM SAI DA FUNCAO
            {
                return;
            }    
      }
        fread(it,sizeof(struct item),90,arquivo_binario);//leu todas as structs item e colocou no vetor struct item it
        //inicia a escrita das tabelas
        printf("Tabela 1: PROCEDIMENTOS CLINICOS (AMBULATORIAIS)-REABILITACOES-SESSOES\n");
        func_gen_linhap();
        for(i=0;i<61;i++)
        {
          printf("Codigo: %d\n", it[i].codigo);
          printf("Descricao: %s\n", it[i].descricao);
          printf("Novo Valor: R$%f\n", it[i].novo_valor);
          printf("Valor Custo: R$%f\n", it[i].valor_custo);
          printf("Valor Auxiliar: R$%f\n", it[i].valor_auxiliar);
          printf("Porte: %d\n", it[i].valor_auxiliar);
          printf("Filme: %d\n", it[i].valor_auxiliar);
          func_gen_linhac();
        }
          printf("Tabela 2: PROCEDIMENTOS CLINICOS (AMBULATORIAIS) - TERAPEUTICA\n");
          func_gen_linhap();
          for(i=60;i<90;i++)
        {
          printf("Codigo: %d\n", it[i].codigo);
          printf("Descricao: %s\n", it[i].descricao);
          printf("Novo Valor: R$%f\n", it[i].novo_valor);
          printf("Valor Custo: R$%f\n", it[i].valor_custo);
          printf("Valor Auxiliar: R$%f\n", it[i].valor_auxiliar);
          printf("Porte: %d\n", it[i].valor_auxiliar);
          printf("Filme: %d\n", it[i].valor_auxiliar);
          func_gen_linhac();
        }
      fclose(arquivo_binario);
      system("PAUSE");
      return;
}
void func_04_01_02_ler_item_especifico()
{
          /*struct item{ int codigo;
                       char descricao[5000]; 
                       float novo_valor;
                       float valor_custo;
                       float valor_auxiliar;
                       int porte;
                       int filme;};*/
          int resposta;
          int i;
          int posicao;
          struct item it_lido;
          func_gen_titulo(" Menu Principal->ED-04 Arquivo",
                          " ",
                          "                                          Visualizacao de Arquivo Binario", 31,
                          "                                        LENDO ITEM ESPECIFICADO PELO USUARIO",
                          "                                        Utilizando a Funcao fseek() e fread()");                                          
          FILE *arquivo_binario = fopen("CONSULTORIO_MEDICO.bin", "rb");
          char linha[5001];
          if (!arquivo_binario)//SE NAO, PERGUNTA SE QUER CRIAR
          {
                printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
                func_gen_linhap();
                printf(">");
                scanf("%d", &resposta);
                if (resposta==1)
                {   
                    func_gen_limpa_tela();
                    func_03_01_03_escrever_arquivo_binario();
                    return;
                }
                else//SE SIM SAI DA FUNCAO
                {
                    return;
                }    
          }
          printf("\t\n\nInforme a posicao do item:\n");
          func_gen_linhap();
          printf(">");
          scanf("%d",&posicao);
          //Posiciona cursor no item que o usuario informou
          fseek(arquivo_binario,((posicao-1)*sizeof(item)),SEEK_SET);
          fread(&it_lido,sizeof(struct item),1,arquivo_binario);
          //Imprimindo item lido
          func_gen_linhac();
          printf("Codigo: %d\n", it_lido.codigo);
          printf("Descricao: %s\n", it_lido.descricao);
          printf("Novo Valor: R$%f\n", it_lido.novo_valor);
          printf("Valor Custo: R$%f\n", it_lido.valor_custo);
          printf("Valor Auxiliar: R$%f\n", it_lido.valor_auxiliar);
          printf("Porte: %d\n", it_lido.valor_auxiliar);
          printf("Filme: %d\n", it_lido.valor_auxiliar);
          func_gen_linhac();
          fclose(arquivo_binario);
          system("PAUSE");
          return;
}
void func_04_01_03_TAD()
{
      func_gen_titulo(" Menu Principal->ED-04 Arquivo XML",
                      " ",
                      "                                                      TAD-04", 31,
                      "                                         ESPECIFICACAO DAS FUNCOES DA TAD-04",
                      " ");                                             
      printf("\n\nNesta atividade, utilizamos os dados da tabela TUSS, onde o codigo e uma variavel do tipo int, a descricao do tipo char, o novo valor e do tipo float, o valor custo e do tipo float, o valor auxiliar e do tipo float, o nivel e do tipo int e o filme e do tipo int. Cada item desse representa uma coluna na tabela tuss. Entao criamos um vetor de struct item para armazenar e escrever esses itens em tela. Devemos lembrar que ao ler do arquivo binario, nao precisamos converter os dados de char para int ou float, pois esses dados ja sao lidos em seus respectivos tipos.\n\nNesta atividade, implementamos 2 funcoes listadas abaixo:\n");
      printf("\n\n\t(1)-func_04_01_01_visualizar_arquivo_binario()\n");
      printf("\n\t(2)-func_04_01_02_ler_item_especifico()\n");
      printf("\n\nA funcao (1), tem como funcionalidade, ler todos os itens do arquivo binario e exibir na tela utilizando a struct item.\n");
      printf("\n\nA funcao (2) assim como a (1), le o arquivo binario, porem utilizando o comando fseek para posicionar o cursor em uma posicao previamente informada pelo usuario.\n");
          
	  printf("\n\n\n");
	  
	  printf("\tVariaveis:\n\n");
	  printf("\t(1) struct item{ int codigo;\n");
	  printf("\t                 char descricao[5000]; \n");
	  printf("\t                 float novo_valor;\n");
	  printf("\t                 float valor_custo;\n");
	  printf("\t                 float valor_auxiliar;\n");
	  printf("\t                 int porte;\n");
	  printf("\t                 int filme;};\n");
	  printf("\t(2) struct item it[90];\n");
	  
      printf("\n\n\n");
      printf("-Explicacao Para Variavel (1)\n *Struct do tipo item, criada para auxiliar a leitura de cada linha das subtabelas tuss contidas no arquivo binario. Essa struct e usada na funcao (1) e (2). Na funcao 1 ela serve apenas para auxiliar o instanciamento da variavel (2), que e um vetor de structs do tipo item. Ja na funcao 2, essa struct e instanciada como it_lido, que serve para armazenar e auxiliar na escrita de cada item lido do arquivo binario.\n\n\n\n");
	  printf("-Explicacao Para Variavel (2)\n *Estrutura complexa que se caracteriza por ser um vetor de 90 posicoes de structs do tipo item. Esse vetor e usado para ler todos os itens contidos no arquivo binario, que por sua vez foi armazenados 1 a 1 como uma struct do tipo item. E claro, esse vetor de structs auxilia na escrita em tela dos itens lidos do arquivo binario.\n\n\n\n");
	 
	  func_gen_linhap();
	 
	 
	 
	  func_gen_linhap();
      system("PAUSE");
}
void func_05_01_01_carregar_codigos()
{
	func_gen_titulo(" Menu Principal->ED-05 Vetor e Matriz -> Carregar Codigos",
                      " ",
                      "                                          Leitura de Vetores e Matrizes", 31,
                      "                                         a partir de dados no arquivo XML.",
                      " ");
    int i;
	int codigo[61];
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
  //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {
            func_gen_limpa_tela();            
            func_03_01_01_escrever_arquivo_xml();
            return;
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<125;i++)//Pula 22 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      for(i=0;i<61;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          codigo[i]=atoi(texto);
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
      }     
	  //escreve os codigos lidos no vetor             
	 printf("\t\n\tCodigos: \n\n\n");
     for(i=0;i<61;i++)
      {   
          printf("\t%d\n",codigo[i]);
      }   
	printf("\n\n\n");
	system("PAUSE");
}
void func_05_01_02_carregar_descricoes()
{
	func_gen_titulo(" Menu Principal->ED-05 Vetor e Matriz -> Carregar Descricoes",
                      " ",
                      "                                          Leitura de Vetores e Matrizes", 31,
                      "                                         a partir de dados no arquivo XML.",
                      " ");
    int i;
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];
    char descricoes[61][5001];
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
  //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {
            func_gen_limpa_tela();            
            func_03_01_01_escrever_arquivo_xml();
            return;
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<125;i++)//Pula 22 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      for(i=0;i<61;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          strcpy(descricoes[i],texto);
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
      }     
	  //escreve os codigos lidos no vetor             
	 printf("\t\n\tDescricoes: \n\n\n");
     for(i=0;i<61;i++)
      {   
          printf("\t->%s\n",descricoes[i]);
      }   
	printf("\n\n\n");
	system("PAUSE");
}
void func_05_01_03_carregar_valores()
{
	func_gen_titulo(" Menu Principal->ED-05 Vetor e Matriz -> Carregar Valores da tag <novo_valor>",
                      " ",
                      "                                          Leitura de Vetores e Matrizes", 31,
                      "                                         a partir de dados no arquivo XML.",
                      " ");
    int i;
	float valor[61];
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
  //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {
            func_gen_limpa_tela();            
            func_03_01_01_escrever_arquivo_xml();
            return;
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<125;i++)//Pula 22 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      for(i=0;i<61;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          valor[i]=atof(texto);
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
      }     
	  //escreve os codigos lidos no vetor             
	 printf("\t\n\tValores: \n\n\n");
     for(i=0;i<61;i++)
      {   
          printf("\t -> R$ %0.2f \n",valor[i]);
      }   
	printf("\n\n\n");
	system("PAUSE");
}
void func_05_01_04_carregar_matrizes()
{
	func_gen_titulo(" Menu Principal->ED-05 Vetor e Matriz -> Carregar Matrizes de Valores",
                      " ",
                      "                                          Leitura de Vetores e Matrizes", 31,
                      "                                         a partir de dados no arquivo XML.",
                      " ");
    int i;
	float matriz[61][5];
	float matriz2[29][5];
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
  //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {
            func_gen_limpa_tela();            
            func_03_01_01_escrever_arquivo_xml();
            return;
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<125;i++)//Pula 128 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      for(i=0;i<61;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][0]=atof(texto);
          
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][1]=atof(texto);
          
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][2]=atof(texto);
          
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][3]=atof(texto);
          
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][4]=atof(texto);
          
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
      }
       for(i=0;i<29;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][0]=atof(texto);
          
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][1]=atof(texto);
          
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][2]=atof(texto);
          
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][3]=atof(texto);
          
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][4]=atof(texto);
          
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
      }
	  
	  for (i=0;i<189;i++)//Pula 128 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      
	       
	  //escreve os codigos lidos no vetor             
	 printf("\n\t MATRIZ 1: \n\n\n");
	 printf("\n\t   Novo Valor           Valor Custo         Valor Auxiliar      Porte               Filme\n");
     for(i=0;i<61;i++)
      {   
          printf("%20f%20f%20f%20f%20f\n",matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4]);
      }   
	printf("\n\n\n");
	printf("\n\t MATRIZ 2: \n\n\n");
	 printf("\n\t   Novo Valor           Valor Custo         Valor Auxiliar      Porte               Filme\n");
     for(i=0;i<29;i++)
      {   
          printf("%20f%20f%20f%20f%20f\n",matriz2[i][0],matriz2[i][1],matriz2[i][2],matriz2[i][3],matriz2[i][4]);
      }   
	printf("\n\n\n");
	system("PAUSE");
}

void func_05_01_05_somar_colunas()
{
		func_gen_titulo(" Menu Principal->ED-05 Vetor e Matriz -> Somar Colunas da Matriz",
                      " ",
                      "                                          Leitura de Vetores e Matrizes", 31,
                      "                                         a partir de dados no arquivo XML.",
                      " ");
    int i;
	float matriz[61][5];
	float matriz2[29][5];
	float vet_soma1[5]={0};
	float vet_soma2[5]={0};
	float soma;
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
  //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {
            func_gen_limpa_tela();            
            func_03_01_01_escrever_arquivo_xml();
            return;
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<125;i++)//Pula 128 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      
      for(i=0;i<61;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][0]=atof(texto);
          vet_soma1[0]=vet_soma1[0]+matriz[i][0];
          
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][1]=atof(texto);
          vet_soma1[1]=vet_soma1[1]+matriz[i][1];
          
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][2]=atof(texto);
          vet_soma1[2]=vet_soma1[2]+matriz[i][2];
          
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][3]=atof(texto);
          vet_soma1[3]=vet_soma1[3]+matriz[i][3];
          
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz[i][4]=atof(texto);
          vet_soma1[4]=vet_soma1[4]+matriz[i][4];
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
      }
      
      for (i=0;i<3;i++)//Pula 3 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
     
      
       for(i=0;i<29;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][0]=atof(texto);
          vet_soma2[0]=vet_soma2[0]+matriz2[i][0];
          soma=soma+matriz2[i][0];
          
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][1]=atof(texto);
          vet_soma2[1]=vet_soma2[1]+matriz2[i][1];
          
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][2]=atof(texto);
          vet_soma2[2]=vet_soma2[2]+matriz2[i][2];
          
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][3]=atof(texto);
          vet_soma2[3]=vet_soma2[3]+matriz2[i][3];
          
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          matriz2[i][4]=atof(texto);
          vet_soma2[4]=vet_soma2[4]+matriz2[i][4];
          
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
      }   
	  //escreve os codigos lidos no vetor             
	 printf("\n\t MATRIZ 1: \n\n\n");
	 printf("\n\t   Novo Valor           Valor Custo         Valor Auxiliar      Porte               Filme\n");
     for(i=0;i<61;i++)
      {   
          printf("%20f%20f%20f%20f%20f\n",matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4]);
      } 
	printf("\nSomas: %15f%19f%20f%20f%20f\n",vet_soma1[0],vet_soma1[1],vet_soma1[2],vet_soma1[3],vet_soma1[4]);  
	
	printf("\n\n\n");
	printf("\n\t MATRIZ 2: \n\n\n");
	 printf("\n\t   Novo Valor           Valor Custo         Valor Auxiliar      Porte               Filme\n");
     for(i=0;i<29;i++)
      {   
          printf("%20f%20f%20f%20f%20f\n",matriz2[i][0],matriz2[i][1],matriz2[i][2],matriz2[i][3],matriz2[i][4]);
      } 
	printf("\nSomas:%14f%20f%20f%20f%20f\n",vet_soma2[0],vet_soma2[1],vet_soma2[2],vet_soma2[3],vet_soma2[4]);    
	printf("\n\n\n");
	system("PAUSE");
}
void func_05_01_06_TAD_05()
{
	      func_gen_titulo(" Menu Principal->ED-05 Vetor e Matriz -> TAD-05",
                      " ",
                      "                                                      TAD-05", 31,
                      "                                         ESPECIFICACAO DAS FUNCOES DA TAD-05",
                      " ");                                             
      printf("\n\n Nessa Atividade, implementamos 6 funcoes como descrito abaixo:\n");
      printf("\n\n\t (1) - func_05_01_sub_menu()\n");
      printf("\n\t (2) - func_05_01_01_carregar_codigos()\n");
      printf("\n\t (3) - func_05_01_02_carregar_descricoes()\n");
      printf("\n\t (4) - func_05_01_03_carregar_valores()\n");
      printf("\n\t (5) - func_05_01_04_carregar_matrizes()\n");
      printf("\n\t (6) - func_05_01_05_somar_colunas()\n\n");
      printf("\n\t (1) - Esta funcao e responsavel por gerar o submenu logo apos o usuario selecionar a opcao 5.\n");
      printf("\n\t (2) - Esta funcao e responsavel por ler todos os codigos de todos os itens do arquivo xml correspondentes a atividade ED-05 e carregar em um vetor, logo apos, este vetor e exibido em tela..\n");
      printf("\n\t (3) - Esta funcao e responsavel por ler a descricao de cada idem do ED-05 no arquivo xml e carrega em uma matriz de caracteres. \n");
      printf("\n\t (4) - Esta funcao e responsavel por ler o valor da tag <novo_valor> de cada item do arquivo xml e armazena em um vetor chamado valor com 61 posicoes do tipo float. Logo depois este vetor e escrito em tela. \n");
      printf("\n\t (5) - Esta funcao e responsavel por ler as tags <novo_valor>, <valor_custo>,<valor_auxiliar>,<porte>,<filme> e armazena em uma matriz de 5 colunas de 61 linhas e a subtabela 2 e armazenada em uma matriz de 5 colunas e 28 linhas. Logo depois estas matrizes sao escritas em tela. \n");
      printf("\n\t (6) - Esta funcao como a anterior ler as duas matrizes e armazena em respectivas matrizes do tipo float e faz a soma das colunas da matriz 1 e 2 e armazena no vetor vet_soma1 e vet_soma2 e por fim exibe as matrizes e as somas de suas colunas em tela. \n\n\n \n\n\n");
      
	  printf("\tVariaveis:\n\n");
	  
	  printf("\t(1) char texto[5001];\n");
	  printf("\t(2) int codigo[61]\n");
	  printf("\t(3) char descricoes[61][5001];\n");
	  printf("\t(4) float valor[61];\n");
	  printf("\t(5) float matriz[61][5];;\n");
	  printf("\t(6) float matriz2[29][5];\n");
	  printf("\t(7) float vet_soma1[5]={0};\n");
	  printf("\t(8) float vet_soma2[5]={0};\n");
	  	
	
	   
      printf("\n\n\n");
      printf("-Explicacao Para Variavel (1)\n *Vertor de char que e utilizado para ler os dados do arquivo xml. Esse vetor e utilizado na funcao 2 e logo apos e convertido para um inteiro e armazenado na respectiva posicao da variavel 2, vetor de int instanciado como codigo. Tambem e utilizado na funcao 3 para a leitura de cada descricao de cada item da subtabela tuss contida no arquivo xml.\n\n");
	  printf("-Explicacao Para Variavel (2)\n *Vetor de inteiros de 61 posicoes, responsavel por armazenar cada codigo lido do arquivo xml.\n\n");
	  printf("-Explicacao Para Variavel (3)\n *Matriz de char responsavel por armazenar cada descricao lida em suas linhas.\n\n");
	  printf("-Explicacao Para Variavel (4)\n *Vetor com 61 posicoes do tipo float. Esse vetor e usado na funcao 4 para carregar o campo novo valor de cada linha da tabela tuss.\n\n");
	  printf("-Explicacao Para Variavel (5)\n *Matriz do tipo float com 61 linha e 5 colunas. Nessa matriz e armazenado todos os campos numericos da subtabela 1 contida no arquivo xml no ED-05. Apenas a descricao nao e armazenada nessa matriz pois o seu tipo nao e compativel com o tipo da matriz. Na coluna 0 dessa matriz, e armazenado todos os campos do novo valor. Na coluna 1, sao armazenados todos os campos  valor custo. Na coluna 2 os campos valor auxiliar, na coluna 3 os campos porte e na coluna 4 os campos filme. Essa matriz tambem auxilia a escrita desses valores lidos do arquivo xml de forma organizada.\n\n");
	  printf("-Explicacao Para Variavel (6)\n *Matriz identica a matriz do item (5) porem serve para armazenar a subtabela 2 da tabela tuss.\n\n");
	  printf("-Explicacao Para Variavel (7)\n *Vetor criado para armazenar a soma de cada coluna da matriz. Depois esse vetor e escrito abaixo de cada coluna da matriz.\n\n");
	  printf("-Explicacao Para Variavel (8)\n *Vetor criado para armazenar a soma de cada coluna da matriz2.\n\n\n\n");
	 
	 
	 
	  
	   func_gen_linhap();
	   system("PAUSE");
}
void func_06_01_01_ordenacao_bubblesort()
{
	
	func_gen_titulo(" Menu Principal->ED-06->Ordenar Vetor de itens por ordem crescente de Novos Valores utilizando BubbleSort.",
                    " ",
                    "                                Ordenacao de Vetor de Struct Pelo Metodo BubbleSort", 31,
                    "                              lendo dados no arquivo XML que estao inseridos na TAD-05.",
                    " ");
   
    struct item{ int codigo;
                       char descricao[5000]; 
                       float novo_valor;
                       float valor_custo;
                       float valor_auxiliar;
                       int porte;
                       int filme;};
    struct item it[61];
    struct item it_aux;
    int i;
    int verifica;
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
  //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {
            func_gen_limpa_tela();            
            func_03_01_01_escrever_arquivo_xml();
            return;
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<125;i++)//Pula 125 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      for(i=0;i<61;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].codigo=atoi(texto);

          //lendo descricao
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          strcpy(it[i].descricao,texto);

          //lendo <novo_valor>
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].novo_valor=atof(texto);

          //lendo <valor_custo>
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].valor_custo=atof(texto);
		   
          //lendo <valor_auxiliar>
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].valor_auxiliar=atof(texto);

           //lendo <porte>
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].porte=atoi(texto);

           //lendo <filme>
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].filme=atoi(texto);
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          
      }  
      //Inicia a Ordenacao por bubblesort
      do
      {
	      verifica=1;//inicialmente todos encontram-se ordenados idicado pelo valor zero
	      for(i=0;i<60;i++)
	      {
		     if(it[i].novo_valor>it[i+1].novo_valor)
		     {  
		        it_aux=it[i+1];//pega o item da frente e salva no item auxiliar
				it[i+1]=it[i];//o item da frente recebe o item anterior
				it[i]=it_aux;//o item de traz recebe o item que estava na frente que foi salvo na variavel item auxiliar
				verifica=0;//verifica recebe zero indicando que teve uma ordenacao	
	         }	
		  }
	  }while(verifica==0);
	  //escreve itens apos serem ordenados pelo seu Novo Valor          
	  printf("Tabela 1: PROCEDIMENTOS CLINICOS (AMBULATORIAIS)-REABILITACOES-SESSOES\n");
      func_gen_linhap();
	  for(i=0;i<61;i++)
	    {
	      printf("Codigo: %d\n", it[i].codigo);
	      printf("Descricao: %s\n", it[i].descricao);
	      printf("Novo Valor:");
	      SetConsoleTextAttribute(hConsole, 15);//escreve linha com letra branca
	      printf(" R$%f \n", it[i].novo_valor);
	      SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
	      printf("Valor Custo: R$%f\n", it[i].valor_custo);
	      printf("Valor Auxiliar: R$%f\n", it[i].valor_auxiliar);
	      printf("Porte: %d\n", it[i].valor_auxiliar);
	      printf("Filme: %d\n", it[i].valor_auxiliar);
	      func_gen_linhac();
	    }
	printf("\n\n\n");
	system("PAUSE");
}
void func_06_01_02_pesquisa_binaria()
{
	func_gen_titulo(" Menu Principal->ED-06->Fazer Pesquisa Binaria No Vetor de Itens Por Codigo",
                    " ",
                    "                                Pesquisa binaria em um vetor de structs do tipo item", 31,
                    "                        utilizando o codigo da amostra que já encontra-se ordenado por padrao.",
                    " ");
   
    struct item{ int codigo;
                       char descricao[5000]; 
                       float novo_valor;
                       float valor_custo;
                       float valor_auxiliar;
                       int porte;
                       int filme;};
    struct item it[61];
    struct item it_aux;
    int i;
    int pos;
    int num_loop;
    int codigo;
    int pos_inicial;
    int pos_final;
    int pos_media;
    int verifica;
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
  //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {
            func_gen_limpa_tela();            
            func_03_01_01_escrever_arquivo_xml();
            return;
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<125;i++)//Pula 125 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      for(i=0;i<61;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].codigo=atoi(texto);

          //lendo descricao
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          strcpy(it[i].descricao,texto);

          //lendo <novo_valor>
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].novo_valor=atof(texto);

          //lendo <valor_custo>
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].valor_custo=atof(texto);
		   
          //lendo <valor_auxiliar>
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].valor_auxiliar=atof(texto);

           //lendo <porte>
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].porte=atoi(texto);

           //lendo <filme>
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].filme=atoi(texto);
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          
      } 
      //Pede o codigo ao usuario
      printf("\n\n\tInforme o codigo do item: \n\n\n");
      func_gen_linhap();
      printf(">");
      scanf("%d", &codigo);
      printf("\n");
      func_gen_linhac();
      //inicia a pesquisa binaria
      //inicia as posicoes
      pos_inicial=0;
      pos_final=60;
      pos_media=30;
	  verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou
	  num_loop=0;
	  
	  while(pos_inicial<=pos_inicial)
	  {
	   	 pos_media = (pos_inicial + pos_final) / 2;
		 if (codigo == it[pos_media].codigo)
              {
                 verifica = 1;
                 i=pos_media;
                 break;
              } 
		 else 
			 {
			 	if (codigo < it[pos_media].codigo)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(codigo > it[pos_media].codigo)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
	  }//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item

	  //escreve itens apos serem ordenados pelo seu Novo Valor          
	  
      if(verifica==1)//mostra item
      {
      	  printf("\nItem achado na posicao: %d\n\n", i);
      	  func_gen_linhac();
      	  printf("Tabela 1: PROCEDIMENTOS CLINICOS (AMBULATORIAIS)-REABILITACOES-SESSOES\n");
          func_gen_linhac();
	      printf("Codigo: %d\n", it[i].codigo);
	      printf("Descricao: %s\n", it[i].descricao);
	      printf("Novo Valor:");
	      SetConsoleTextAttribute(hConsole, 15);//escreve linha com letra branca
	      printf(" R$%f \n", it[i].novo_valor);
	      SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
	      printf("Valor Custo: R$%f\n", it[i].valor_custo);
	      printf("Valor Auxiliar: R$%f\n", it[i].valor_auxiliar);
	      printf("Porte: %d\n", it[i].valor_auxiliar);
	      printf("Filme: %d\n", it[i].valor_auxiliar);
	  }
	  else
	  {
	    printf("Valor nao encontrado!\n");
	  }
	  func_gen_linhac();
      printf("\n\n\n");
      system("PAUSE");
}

void func_06_01_03_pesquisa_binaria_debug()
{
		func_gen_titulo(" Menu Principal->ED-06->Fazer Pesquisa Binaria No Vetor de Itens Por Codigo",
                    " ",
                    "                                                    Com DEBUG", 28,
                    "                               Pesquisa binaria em um vetor de structs do tipo item",
                    "                       utilizando o codigo da amostra que já encontra-se ordenado por padrao.");
   
    struct item{ int codigo;
                       char descricao[5000]; 
                       float novo_valor;
                       float valor_custo;
                       float valor_auxiliar;
                       int porte;
                       int filme;};
    struct item it[61];
    struct item it_aux;
    int i;
    int pos;
    int num_loop;
    int codigo;
    int pos_inicial;
    int pos_final;
    int pos_media;
    int verifica;
	int resposta;
    int posicao_leitura;
    int posicao_pos_leitura;
    char texto[5001];
    posicao_leitura=71;
    posicao_pos_leitura=0;
    FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
  //TESTA SE O ARQUIVO EXISTE
      if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
      {
        printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
        func_gen_linhap();
        printf(">");
        scanf("%d", &resposta);
        if (resposta==1)
        {
            func_gen_limpa_tela();            
            func_03_01_01_escrever_arquivo_xml();
            return;
        }
        else//SE SIM SAI DA FUNCAO
        {
            return;
        }    
      }
      fclose (arquivo);
      for (i=0;i<125;i++)//Pula 125 linhas ate começar ler os dados da tabela
      { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;   
      }
      for(i=0;i<61;i++)
      {   
          //lendo codigo
          func_gen_ler_tag("<codigo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].codigo=atoi(texto);

          //lendo descricao
          func_gen_ler_tag("<descricao>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          strcpy(it[i].descricao,texto);

          //lendo <novo_valor>
          func_gen_ler_tag("<novo_valor>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].novo_valor=atof(texto);

          //lendo <valor_custo>
          func_gen_ler_tag("<valor_custo>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].valor_custo=atof(texto);
		   
          //lendo <valor_auxiliar>
          func_gen_ler_tag("<valor_auxiliar>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].valor_auxiliar=atof(texto);

           //lendo <porte>
          func_gen_ler_tag("<porte>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].porte=atoi(texto);

           //lendo <filme>
          func_gen_ler_tag("<filme>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          it[i].filme=atoi(texto);
          //pula linha
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          
      } 
      //Pede o codigo ao usuario
      printf("\n\n\tInforme o codigo do item: \n\n\n");
      func_gen_linhap();
      printf(">");
      scanf("%d", &codigo);
      printf("\n");
      func_gen_linhac();
      //inicia a pesquisa binaria
      //inicia as posicoes
      pos_inicial=0;
      pos_final=60;
      pos_media=30;
	  verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou
	  num_loop=0;
	  
	  while(pos_inicial<=pos_inicial)
	  {
	   	 pos_media = (pos_inicial + pos_final) / 2;
	  	 num_loop=num_loop+1;
	  	 printf("-------------------\n");
	  	 printf("Loop de numero %d\n", num_loop);
	  	 printf("-------------------\n");
	  	 printf("Pos_inicial: %d\n", pos_inicial);
	  	 printf("Pos_imedia: %d\n", pos_media);
	  	 printf("Pos_final: %d\n\n\n", pos_final);
	  	 system("PAUSE");
		 if (codigo == it[pos_media].codigo)
              {
                 verifica = 1;
                 i=pos_media;
                 break;
              } 
		 else 
			 {
			 	if (codigo < it[pos_media].codigo)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(codigo > it[pos_media].codigo)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
	  }//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item

	  //escreve itens apos serem ordenados pelo seu Novo Valor          
	  
      if(verifica==1)//mostra item
      {
      	  printf("\nItem achado na posicao: %d\n\n", i);
      	  func_gen_linhac();
      	  printf("Tabela 1: PROCEDIMENTOS CLINICOS (AMBULATORIAIS)-REABILITACOES-SESSOES\n");
          func_gen_linhac();
	      printf("Codigo: %d\n", it[i].codigo);
	      printf("Descricao: %s\n", it[i].descricao);
	      printf("Novo Valor:");
	      SetConsoleTextAttribute(hConsole, 15);//escreve linha com letra branca
	      printf(" R$%f \n", it[i].novo_valor);
	      SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
	      printf("Valor Custo: R$%f\n", it[i].valor_custo);
	      printf("Valor Auxiliar: R$%f\n", it[i].valor_auxiliar);
	      printf("Porte: %d\n", it[i].valor_auxiliar);
	      printf("Filme: %d\n", it[i].valor_auxiliar);
	  }
	  else
	  {
	    printf("Valor nao encontrado!\n");
	  }
	  func_gen_linhac();
      printf("\n\n\n");
      system("PAUSE");
}

void func_06_01_04_TAD_06()
{
	 func_gen_titulo(" Menu Principal->ED-06->TAD-06",
                    " ",
                    "                                                    TAD-06", 31,
                    "                                         ESPECIFICACAO DAS FUNCOES DA TAD-0",
                    " ");
      printf("\n\n Nessa Atividade, implementamos 4 funcoes como descrito abaixo:\n");
      printf("\n\n\t (1) - func_06_01_sub_menu()\n");
      printf("\n\t (2) - func_06_01_01_ordenacao_bubblesort()\n");
      printf("\n\t (3) - func_06_01_02_pesquisa_binaria()\n");
      printf("\n\t (4) - func_06_01_03_pesquisa_binaria_debug()\n\n");
      printf("\n\t (1) - Esta funcao e responsavel por gerar o submenu logo apos o usuario selecionar a opcao 6.\n");
      printf("\n\t (2) - Esta funcao cria uma struct do tipo item, com os campos referente aos itens no arquivo xml(codigo, descricao, novo_valor, etc...), depois le os dados do arquivo xml que esta no ED-05 e carrega no vetor de structs do tipo item. Logo apos, faz uma ordenacao crescente pela variavel novo_valor da struct item e organiza os item segundo a ordem crescente desta variavel. Depois de fazer o bubblesort no vetor de itens, exibe todos os itens ja ordenados em tela.\n");
      printf("\n\t (3) - Esta funcao primeiramente cria uma struct do tipo item, e depois le todos os itens da subtabela 1 da tuss que esta no arquivo xml no ED-05, e depois atribui todos esses itens a um vetor de structs do tipo item contendo todos os campos correspondente a cada item. Depois, pede ao usuario para informar um codigo para fazer a pesquisa. Entao e feita uma pesquisa nesse vetor de structs itens por codigo do item utilizando o metodo de pesquisa binaria. Apos o item encontrado, o mesmo e mostrado em tela, caso o item nao seja encontrado, o programa informa a mensagem item inexistente.\n");
      printf("\n\t (4) - Esta funcao faz o mesmo que que a funcao acima, porem, esta funcao debuga(mostra) o passo a passo da pesquisa binaria, mostrando quem e a posicao final media e inicial calculada em cada looping e claro, e possivel ver a quantidade de loopings necessarios como sugerido no exercicio. \n\n\n");
      printf("\tVariaveis:\n\n");
	  printf("\t(1) struct item{ int codigo;\n");
	  printf("\t                 char descricao[5000]; \n");
	  printf("\t                 float novo_valor;\n");
	  printf("\t                 float valor_custo;\n");
	  printf("\t                 float valor_auxiliar;\n");
	  printf("\t                 int porte;\n");
	  printf("\t                 int filme;};\n");
	  printf("\t(2) struct item it[61];\n");
	  printf("\t(3) struct item it_aux;\n");
      printf("\n\n\n");
      printf("-Explicacao Para Variavel (1)\n *Struct item, que contem todos os campos de uma linha da tabela TUSS. Essa struct foi criada para auxiliar na organizacao da subtabela 1. Cada linha da tabea tuss e armazenada na memoria volatil no formato de uma struct item. Essa struct e usada nas funcoes 2 3 e 4.\n\n");
      printf("-Explicacao Para Variavel (2)\n *Vetor de structs do tipo item para armazenar cada linha da subtabela 1 contida no ED-05 no arquivo xml. O programa instancia um vetor de itens chamado it e le cada linha e aramazena na respectiva posicao desse vetor de structs item. Esse vetor e usado nas funcoes 2 3 e 4. Na funcao 2 onde e feito uma organizacao pelo metodo bubblesort. Na funcao 3 e 4 onde e feito uma pesquisa binaria nesse vetor. \n\n");
      printf("-Explicacao Para Variavel (3)\n *it_aux e uma struct do tipo item, e e utilizada na funcao 2, para auxiliar no processo de organizacao por bubblesorte. Neste processo se faz necessario um vetor a ser organizado e uma variavel do mesmo tipo do vetor, que no nosso caso o tipo e uma struct item. \n\n");
	  func_gen_linhap();
	  system("PAUSE");
}
void func_07_01_01_ver_consultas()
{
	func_gen_titulo(" Menu Principal->ED-07->Manipulacao de estrutura com leitura do arquivo XML.",
                    " ",
                    "                                Visualizacao de todas as consultas medicas existentes", 31,
                    "                                           no ED-07 a partir do arquivo XML",
                    " ");
	struct consulta vet_consulta[11];               
    int i;
	int resposta;
    char texto[5001];//usado para auxiliar a leitura do XML
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//passa o  vetor de consulta por parametro para a funcao ler as consultas (vet_consulta, tamanho)  
	func_gen_ler_vetor_consultas(vet_consulta, 11);
	//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
	if(vet_consulta[1].numero_consulta==-1)
	{
		return;
	}  
	//Depois de ter lido todas as consultas no arquivo XML, o programa vai escrever em tela o vetor de consultas
	//escreve itens apos serem ordenados pelo seu Novo Valor          
	printf("Consultas realizadas em um consultorio medico do plano de saude Unimed Maringa.\n");
	func_gen_linhap();
	for(i=0;i<11;i++)
	{
		  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
		  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
		  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
		  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
		  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
		  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
		  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
		  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
		  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
		  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
		  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
		  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
		  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
		  func_gen_linhac(); 
	}
	printf("\n\n\n");
	system("PAUSE");
}
void func_07_01_02_calcular_valor_total_consulta()
{
		func_gen_titulo(" Menu Principal->ED-07->Calcular valor total de uma consulta..",
		            " ",
		            "                                Calculando valor toral de uma consulta a partir do", 31,
		            "                                     numero da consulta informado pelo usuario",
		            " ");
		struct consulta vet_consulta[11];               
		int i;
		int resposta;
		char texto[5001];//usado para auxiliar a leitura do XML
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//passa o  vetor de consulta por parametro para a funcao ler as consultas (vet_consulta, tamanho)  
		func_gen_ler_vetor_consultas(vet_consulta, 11);
		//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
		if(vet_consulta[1].numero_consulta==-1)
		{
		return;
		} 
		//Pergunta o numero da consulta para pesquisar no vetor
		printf("\t\nInforme o numero da consulta:\n\n"); 
		func_gen_linhap();
		printf(">");
		scanf("%d", &resposta);
		func_gen_linhap();
		//inicia a pesquisa binaria
		//inicia as posicoes
		int pos_inicial=0;
		int pos_final=11;
		int pos_media=5;
		int verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou  
		while(pos_inicial<=pos_inicial)
		{
		 pos_media = (pos_inicial + pos_final) / 2;
		 if (resposta == vet_consulta[pos_media].numero_consulta)
		      {
		         verifica = 1;
		         i=pos_media;
		         break;
		      } 
		 else 
			 {
			 	if (resposta < vet_consulta[pos_media].numero_consulta)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(resposta > vet_consulta[pos_media].numero_consulta)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
		}//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item
		//escreve itens apos serem ordenados pelo seu Novo Valor    
		if(verifica==1)//mostra item
		{
			  	  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
				  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
				  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
				  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
				  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
				  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
				  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
				  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
				  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
				  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
				  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
				  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
				  func_gen_linhac(); 
				  printf("Valor Total: ");
				  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
				  printf("R$%0.2f\n",(vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo));
				  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
		}
		else
		{
			  	  printf("Consulta nao encontrada!\n");
		}
		func_gen_linhap();
		printf("\n\n\n");
		system("PAUSE");
}
void func_07_01_03_calcular_valor_desconto_consulta()
{
		func_gen_titulo(" Menu Principal->ED-07->Calcular valor com desconto de uma consulta..",
		                " ",
		                "                                  Calculando o valor de uma consulta com desconto", 31,
		                "                               a partir do numero da consulta informado pelo usuario.",
		                " ");
		struct consulta vet_consulta[11];               
		int i;
		int resposta;
		char texto[5001];//usado para auxiliar a leitura do XML
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//passa o  vetor de consulta por parametro para a funcao ler as consultas (vet_consulta, tamanho)  
		func_gen_ler_vetor_consultas(vet_consulta, 11);
		//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
		if(vet_consulta[1].numero_consulta==-1)
		{
			return;
		} 
		//Pergunta o numero da consulta para pesquisar no vetor
		printf("\t\nInforme o numero da consulta:\n\n"); 
		func_gen_linhap();
		printf(">");
		scanf("%d", &resposta);
		func_gen_linhap();
		//inicia a pesquisa binaria
		//inicia as posicoes
		int pos_inicial=0;
		int pos_final=11;
		int pos_media=5;
		int verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou  
		while(pos_inicial<=pos_inicial)
		{
		 pos_media = (pos_inicial + pos_final) / 2;
		 if (resposta == vet_consulta[pos_media].numero_consulta)
		      {
		         verifica = 1;
		         i=pos_media;
		         break;
		      } 
		 else 
			 {
			 	if (resposta < vet_consulta[pos_media].numero_consulta)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(resposta > vet_consulta[pos_media].numero_consulta)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
		}//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item
		//escreve itens apos serem ordenados pelo seu Novo Valor    
		if(verifica==1)//mostra item
		{
			  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
			  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
			  func_gen_linhac();
			  printf("Valor Total       : ");
			  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			  printf("R$%0.2f\n",(vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo));
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Valor com desconto: ");
			  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			  printf("R$%0.2f\n",((vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo)-vet_consulta[i].item_consulta.valor_auxiliar));
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
		}
		else
		{
			  printf("Consulta nao encontrada!\n");
		}
		func_gen_linhap();
		printf("\n\n\n");
		system("PAUSE");
}
void func_07_01_04_TAD_07()
{
		func_gen_titulo(" Menu Principal->ED-07->TAD-07",
                    " ",
                    "                                                    TAD-07", 31,
                    "                                         ESPECIFICACAO DAS FUNCOES DO TAD-07",
                    " ");
      printf("\n\t Essa TAD-07 teve como objetivo manipular uma estrutura com pelomenos 10 campos e 2 funcoes tads. Inseriu-se no arquivo XML dentro da tag ED-07 uma lista de 11 consultas medicas onde contem como subcampo o numero da consulta, o nome do paciente, a data da consulta e o procedimento realizado seguido de seus detalhes. Nessa TAD tambem, optou-se por tornar os tipos de struct item, data e consulta como globais, anteriormente essas structs eram declaradas dentro das funcoes quando se fazia necessario o seu uso.\n");
	  printf("\n Nessa Atividade, implementamos 4 funcoes como descrito abaixo:\n");
      printf("\n\t (1) - func_gen_ler_vetor_consultas(struct consulta *_consulta, int n)\n");
      printf("\n\t (2) - func_07_01_01_ver_consultas()\n");
      printf("\n\t (3) - func_07_01_02_calcular_valor_total_consulta()\n");
      printf("\n\t (4) - func_07_01_02_calcular_valor_deconto_consulta()\n\n");
      printf("\n\t (1) - Essa funcao foi criada pois virificou-se a necessidade de ler em duas duas funcoes para essa TAD e em duas funcoes para a TAD-08 um vetor de structs do tipo consulta.\n");
      printf("\n\t (2) - Essa funcao utiliza da funcao 1 para ler o arquivo xml e retornar um vetor de structs do tipo consulta. E logo apos, exibe todas as consultas existentes no arquivo XML em tela.\n");
	  printf("\n\t (3) - Essa funcao pede ao usuario o numero da consulta, realiza uma pesquisa binaria num vetor de structs do tipo consulta e calcula o valor total da consulta somando os campos novo_valor e valor_auxiliar.\n");
      printf("\n\t (4) - Essa funcao faz as mesmas coisas da funcao 2, e tambem calcula no final o valor com desconto da consulta exiida em tela. Esse calculo e feito subtraindo do valor total o campo valor_auxiliar.\n");
      printf("\tVariaveis:\n\n");
	  printf("\t(1)     struct item{ int codigo;\n");
	  printf("\t                     char descricao[5000]; \n");
	  printf("\t                     float novo_valor;\n");
	  printf("\t                     float valor_custo;\n");
	  printf("\t                     float valor_auxiliar;\n");
	  printf("\t                     int porte;\n");
	  printf("\t                     int filme;};\n");
	  printf("\t(2)     struct data{ int ano;\n");
	  printf("\t                     int dia; \n");
	  printf("\t                     int mes;};\n");
	  printf("\t(3) struct consulta{ int numero_consulta;\n");
	  printf("\t                     char nome_paciente[5000];\n");
	  printf("\t                     struct data data_consulta;\n");
	  printf("\t                     struct item item_consulta;;};\n");
	  printf("\t(4)struct consulta vet_consulta[11];\n");
	  
      printf("\n\n\n");
      printf("-Explicacao Para Variavel (1)\n *Struct item, que contem todos os campos de uma linha da tabela TUSS. Essa struct foi criada para auxiliar na manipulacao de linhas da tabela TUSS da unimed de Maringa. Essa struct e usada nas funcoes 1, 2, 3 e 4.\n\n");
      printf("-Explicacao Para Variavel (2)\n *Struct data, Essa struct possui os campos dia, me e ano, do tipo inteiro e foi criada apenas para armazenar a data da consulta na (3)struct consulta.\n\n");
      printf("-Explicacao Para Variavel (3)\n *Struct consulta, Essa struct possui todos os campos da tag consulta que esta no arquivo XML. Sendo eles: numero da consulta do tipo int, nome_paciente do tipo char[], data_consulta do tipo struct data e item_consulta do tipo struct item. Essa struct foi criada para fazer possivel a modelagem da tag consulta presente no arquivo XML na TAD-07.\n\n");
      printf("-Explicacao Para Variavel (4)\n *Vetor de structs consulta. Esse vetor foi criado para organizar todas os dados continos na tag consulta do arquivo XML. Por haver tambem a necessidade de fazer uma pesquisa binaria, esse vetor facilitou a realizacao da pesquisa binaria nas funcoes 3 e 4.\n\n");
	  system("PAUSE");
}
void func_08_01_01_ecolher_consulta()
{
	func_gen_titulo(" Menu Principal->ED-08->Escolher consulta por numero.",
		                " ",
		                "          Exibindo informacoes de uma consulta em um vetor de structs do tipo consulta", 31,
		                "          utilizando o numero da consulta.",
		                " ");
		struct consulta vet_consulta[11];               
		int i;
		int resposta;
		char texto[5001];//usado para auxiliar a leitura do XML
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//passa o  vetor de consulta por parametro para a funcao ler as consultas (vet_consulta, tamanho)  
		func_gen_ler_vetor_consultas(vet_consulta, 11);
		//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
		if(vet_consulta[1].numero_consulta==-1)
		{
			return;
		} 
		//Pergunta o numero da consulta para pesquisar no vetor
		printf("\t\nInforme o numero da consulta:\n\n"); 
		func_gen_linhap();
		printf(">");
		scanf("%d", &resposta);
		func_gen_linhap();
		//inicia a pesquisa binaria
		//inicia as posicoes
		int pos_inicial=0;
		int pos_final=11;
		int pos_media=5;
		int verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou  
		while(pos_inicial<=pos_inicial)
		{
		 pos_media = (pos_inicial + pos_final) / 2;
		 if (resposta == vet_consulta[pos_media].numero_consulta)
		      {
		         verifica = 1;
		         i=pos_media;
		         break;
		      } 
		 else 
			 {
			 	if (resposta < vet_consulta[pos_media].numero_consulta)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(resposta > vet_consulta[pos_media].numero_consulta)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
		}//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item
		//escreve itens apos serem ordenados pelo seu Novo Valor    
		if(verifica==1)//mostra item
		{
			  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
			  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
			  func_gen_linhac();
			  printf("Valor Total       : ");
			  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			  printf("R$%0.2f\n",(vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo));
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Valor com desconto: ");
			  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			  printf("R$%0.2f\n",((vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo)-vet_consulta[i].item_consulta.valor_auxiliar));
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
		}
		else
		{
			  printf("Consulta nao encontrada!\n");
		}
		func_gen_linhap();
		printf("\n\n\n");
		system("PAUSE");
	
}
void func_08_01_02_sortear_consulta()
{
		func_gen_titulo(" Menu Principal->ED-08->Sortear uma consulta.",
		                " ",
		                "          Exibindo informacoes de uma consulta escolhida aleatoriamente", 31,
		                "          em um vetor de structs do tipo consulta.",
		                " ");
		struct consulta vet_consulta[11];               
		int i;
		int resposta;
		char texto[5001];//usado para auxiliar a leitura do XML
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//passa o  vetor de consulta por parametro para a funcao ler as consultas (vet_consulta, tamanho)  
		func_gen_ler_vetor_consultas(vet_consulta, 11);
		//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
		if(vet_consulta[1].numero_consulta==-1)
		{
			return;
		} 
		srand( (unsigned)time(NULL) );//inicia o rand
		i=rand() % 11;//Sortei um numero entre 0 e 10.
		//escreve a consulta sorteada
		printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
		printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
		printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
		SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
		printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
		SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
		printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
		printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
		printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
		printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
		printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
		printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
		printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
		func_gen_linhac();
		printf("Valor Total       : ");
		SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
		printf("R$%0.2f\n",(vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo));
		SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
		printf("Valor com desconto: ");
		SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
		printf("R$%0.2f\n",((vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo)-vet_consulta[i].item_consulta.valor_auxiliar));
		SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
		func_gen_linhap();
		printf("\n\n\n");
		system("PAUSE");
}
void func_08_01_03_TAD_08()
{
	  func_gen_titulo(" Menu Principal->ED-08->TAD-08",
                    " ",
                    "                                                    TAD-08", 31,
                    "                                         ESPECIFICACAO DAS FUNCOES DO TAD-08",
                    " ");
      printf("\n\t Essa TAD-08 teve como objetivo manipular uma estrutura complexa com pelomenos 5 campos e 5 ocorrencias. Entao foi criada a struct consulta, possuindo campos do tipo int, vetor de char e campos que tambem sao estruturas, como o campo data_consulta e item_consulta. Tambem criou-se um vetor de estruturas do tipo consulta.\n");
	  printf("\n Nessa Atividade, implementamos 2 funcoes como descrito abaixo:\n");
      printf("\n\t (1) - func_08_01_01_escolher_consulta()\n");
      printf("\n\t (2) - func_08_01_02_sortear_consulta()\n");
      printf("\n\t (1) - Essa funcao pede ao usuario o numero de uma consulta e faz uma pesquisa binaria em um vetor de struct consulta previamente lido do arquivo XML. Depois exibe em tela o resultado.\n");
      printf("\n\t (2) - Essa funcao ao ser escolhida, sorteia uma posicao do vetor usando a funcao rand e srand e entao exibe na tela a respectiva consulta.\n");
	  
	  printf("\n\t Como no TAD-07, o TAD-08 tambem utilizou as estruturas listadas abaixo e um vetor de estrutura do tipo consulta.");
	  printf("\t\nVariaveis:\n\n");
	  printf("\t(1)     struct item{ int codigo;\n");
	  printf("\t                     char descricao[5000]; \n");
	  printf("\t                     float novo_valor;\n");
	  printf("\t                     float valor_custo;\n");
	  printf("\t                     float valor_auxiliar;\n");
	  printf("\t                     int porte;\n");
	  printf("\t                     int filme;};\n");
	  printf("\t(2)     struct data{ int ano;\n");
	  printf("\t                     int dia; \n");
	  printf("\t                     int mes;};\n");
	  printf("\t(3) struct consulta{ int numero_consulta;\n");
	  printf("\t                     char nome_paciente[5000];\n");
	  printf("\t                     struct data data_consulta;\n");
	  printf("\t                     struct item item_consulta;;};\n");
	  printf("\t(4)struct consulta vet_consulta[11];\n");
	  
      printf("\n\n\n");
      printf("-Explicacao Para Variavel (1)\n *Struct item, que contem todos os campos de uma linha da tabela TUSS. Essa struct foi criada para auxiliar na manipulacao de linhas da tabela TUSS da unimed de Maringa. Essa struct e usada nas funcoes 1 e 2.\n\n");
      printf("-Explicacao Para Variavel (2)\n *Struct data, Essa struct possui os campos dia, me e ano, do tipo inteiro e foi criada apenas para armazenar a data da consulta na (3)struct consulta.\n\n");
      printf("-Explicacao Para Variavel (3)\n *Struct consulta, Essa struct possui todos os campos da tag consulta que esta no arquivo XML. Sendo eles: numero da consulta do tipo int, nome_paciente do tipo char[], data_consulta do tipo struct data e item_consulta do tipo struct item. Essa struct foi criada para fazer possivel a modelagem da tag consulta presente no arquivo XML na TAD-07.\n\n");
      printf("-Explicacao Para Variavel (4)\n *Vetor de structs consulta. Esse vetor foi criado para organizar todas os dados continos na tag consulta do arquivo XML. Por haver tambem a necessidade de fazer uma pesquisa binaria, esse vetor facilitou a realizacao da pesquisa binaria nas funcoes 1 e 2.\n\n");
	  system("PAUSE");
}
void func_09_01_01_escrever_arquivo_textual(){
	    func_gen_titulo(" Menu Principal->ED-09->Escrever arquivo sequencial textual.",
		                " ",
		                "         Le os dados do arquivo XML presente na ED-07 no arquivo XML", 31,
		                "         e escreve um arquivo de texto sequencial.",
		                " ");
		struct consulta vet_consulta[11];               
		int i;
		int resposta;
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//passa o  vetor de consulta por parametro para a funcao ler as consultas (vet_consulta, tamanho)  
		func_gen_ler_vetor_consultas(vet_consulta, 11);
		//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
		if(vet_consulta[1].numero_consulta==-1)
		{
			return;
		}
		FILE *arquivoSequencialTextual = fopen("arquivo_sequencial_textual.txt", "w");
		for(i=0;i<11;i++)
		{
			  fprintf(arquivoSequencialTextual,"Numero_da_Consulta=%d\n", vet_consulta[i].numero_consulta);
			  fprintf(arquivoSequencialTextual,"Nome_do_Paciente=%s\n", vet_consulta[i].nome_paciente);
			  fprintf(arquivoSequencialTextual,"Dia=%d\n", vet_consulta[i].data_consulta.dia);
			  fprintf(arquivoSequencialTextual,"Mes=%d\n", vet_consulta[i].data_consulta.mes);
			  fprintf(arquivoSequencialTextual,"Ano=%d\n", vet_consulta[i].data_consulta.ano);
			  fprintf(arquivoSequencialTextual,"Codigo=%d\n", vet_consulta[i].item_consulta.codigo);
			  fprintf(arquivoSequencialTextual,"Descricao=%s\n", vet_consulta[i].item_consulta.descricao);
			  fprintf(arquivoSequencialTextual,"Novo_Valor=%f \n", vet_consulta[i].item_consulta.novo_valor);
			  fprintf(arquivoSequencialTextual,"Valor_Custo=%f\n", vet_consulta[i].item_consulta.valor_custo);
			  fprintf(arquivoSequencialTextual,"Valor_Auxiliar=%f\n", vet_consulta[i].item_consulta.valor_auxiliar);
			  fprintf(arquivoSequencialTextual,"Porte=%d\n", vet_consulta[i].item_consulta.porte);
			  fprintf(arquivoSequencialTextual,"Filme=%d\n", vet_consulta[i].item_consulta.filme);
		}		
		fclose (arquivoSequencialTextual);
		printf("\n\n\n\tArquivo sequencial textual de nome arquivo_sequencial_textual.txt escrito com sucesso!\n\n\n\n");
		func_gen_linhap();
		system("PAUSE");
}
void func_09_01_02_ler_arquivo_textual(){
	    func_gen_titulo(" Menu Principal->ED-09->Ler arquivo sequencial textual.",
		                " ",
		                "         Le os dados do arquivo squencial textual", 31,
		                "         e escreve na tela.",
		                " ");
		struct consulta vet_consulta[11];               
		int i,j,k;
		int nivel;
		int resposta;
		char texto[5001];//usado para uaxiliar na leitura de uma linha inteira
		char texto_aux[5001];
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		FILE *arquivoSequencialTextual = fopen("arquivo_sequencial_textual.txt", "r");
  		if (!arquivoSequencialTextual)//SE NAO, PERGUNTA SE QUER CRIAR
		{
			printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
			func_gen_linhap();
			printf(">");
			scanf("%d", &resposta);
			if (resposta==1)
			{
			    func_gen_limpa_tela();            
			    func_09_01_01_escrever_arquivo_textual();
			    return;
			}
		}
		j=0;//para correr o vetor texto
		k=0;//para correr o vetor texto_aux
		nivel=0;//nivel =o nao le a char, =1 le a char
		for(i=0;i<11;i++)
		{
			  fscanf(arquivoSequencialTextual,"Numero_da_Consulta=%d\n", &vet_consulta[i].numero_consulta);
			  //lendo a linha inteira
			  fgets(texto, sizeof(texto), arquivoSequencialTextual);
			  //tratando texto
			  for(j=0;j<5001;j++){
			  	    if(texto[j]==10)//testa se chegou ao final do campo
					{
				  	 	nivel=0;
				  	 	texto_aux[k]='\0';//finaliza linha
				  	 	k=0;//zera o k para voltar ao inicio do vetor texto_aux na proxima leitura
				  	 	break;//para o loop
					}	
			  		if(nivel==1)
					{
					 	texto_aux[k]=texto[j];
					 	k++;
					}
			  		if(texto[j]=='=')//começa a ler a informacao do campo
					{
			  	 		nivel=1;
					}
					
			  }
			  strcpy(vet_consulta[i].nome_paciente, texto_aux);
			  fscanf(arquivoSequencialTextual,"Dia=%d\n", &vet_consulta[i].data_consulta.dia);
			  fscanf(arquivoSequencialTextual,"Mes=%d\n", &vet_consulta[i].data_consulta.mes);
			  fscanf(arquivoSequencialTextual,"Ano=%d\n", &vet_consulta[i].data_consulta.ano);
			  fscanf(arquivoSequencialTextual,"Codigo=%d\n", &vet_consulta[i].item_consulta.codigo);
			  //lendo a linha inteira
			  fgets(texto, sizeof(texto), arquivoSequencialTextual);
			  //tratando texto
			  for(j=0;j<5001;j++){
			  	    if(texto[j]==10)//testa se chegou ao final do campo
					{
				  	 	nivel=0;
				  	 	texto_aux[k]='\0';//finaliza linha
				  	 	k=0;//zera o k para voltar ao inicio do vetor texto_aux na proxima leitura
				  	 	break;//para o loop
					}	
			  		if(nivel==1)
					{
					 	texto_aux[k]=texto[j];
					 	k++;
					}
			  		if(texto[j]=='=')//começa a ler a informacao do campo
					{
			  	 		nivel=1;
					}
					
			  }
			  strcpy(vet_consulta[i].item_consulta.descricao, texto_aux);
			  fscanf(arquivoSequencialTextual,"Novo_Valor=%f \n", &vet_consulta[i].item_consulta.novo_valor);
			  fscanf(arquivoSequencialTextual,"Valor_Custo=%f\n", &vet_consulta[i].item_consulta.valor_custo);
			  fscanf(arquivoSequencialTextual,"Valor_Auxiliar=%f\n", &vet_consulta[i].item_consulta.valor_auxiliar);
			  fscanf(arquivoSequencialTextual,"Porte=%d\n", &vet_consulta[i].item_consulta.porte);
			  fscanf(arquivoSequencialTextual,"Filme=%d\n", &vet_consulta[i].item_consulta.filme);
		}		
		fclose (arquivoSequencialTextual);
		printf("Dados Lidos do Arquivo Sequencial Textual.\n");
		func_gen_linhap();
		for(i=0;i<11;i++)
		{
			  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
			  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
			  func_gen_linhac(); 
		}
		printf("\n\n\n");
		system("PAUSE");
}
void func_09_01_03_calcular_valor_total(){
     	func_gen_titulo(" Menu Principal->ED-09->Calcular valor total da consulta.",
		                " ",
		                "         -Le os dados do arquivo squencial textual.", 31,
		                "         -Pede a posicao do dado.",
		                "         -Calcula o valor total da consulta e exibe em tela.");
		struct consulta vet_consulta[11];               
		int i,j,k;
		int nivel;
		int resposta;
		char texto[5001];//usado para uaxiliar na leitura de uma linha inteira
		char texto_aux[5001];
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		FILE *arquivoSequencialTextual = fopen("arquivo_sequencial_textual.txt", "r");
  		if (!arquivoSequencialTextual)//SE NAO, PERGUNTA SE QUER CRIAR
		{
			printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
			func_gen_linhap();
			printf(">");
			scanf("%d", &resposta);
			if (resposta==1)
			{
			    func_gen_limpa_tela();            
			    func_09_01_01_escrever_arquivo_textual();
			    return;
			}
		}
		j=0;//para correr o vetor texto
		k=0;//para correr o vetor texto_aux
		nivel=0;//nivel =o nao le a char, =1 le a char
		for(i=0;i<11;i++)
		{
			  fscanf(arquivoSequencialTextual,"Numero_da_Consulta=%d\n", &vet_consulta[i].numero_consulta);
			  //lendo a linha inteira
			  fgets(texto, sizeof(texto), arquivoSequencialTextual);
			  //tratando texto
			  for(j=0;j<5001;j++){
			  	    if(texto[j]==10)//testa se chegou ao final do campo
					{
				  	 	nivel=0;
				  	 	texto_aux[k]='\0';//finaliza linha
				  	 	k=0;//zera o k para voltar ao inicio do vetor texto_aux na proxima leitura
				  	 	break;//para o loop
					}	
			  		if(nivel==1)
					{
					 	texto_aux[k]=texto[j];
					 	k++;
					}
			  		if(texto[j]=='=')//começa a ler a informacao do campo
					{
			  	 		nivel=1;
					}
					
			  }
			  strcpy(vet_consulta[i].nome_paciente, texto_aux);
			  fscanf(arquivoSequencialTextual,"Dia=%d\n", &vet_consulta[i].data_consulta.dia);
			  fscanf(arquivoSequencialTextual,"Mes=%d\n", &vet_consulta[i].data_consulta.mes);
			  fscanf(arquivoSequencialTextual,"Ano=%d\n", &vet_consulta[i].data_consulta.ano);
			  fscanf(arquivoSequencialTextual,"Codigo=%d\n", &vet_consulta[i].item_consulta.codigo);
			  //lendo a linha inteira
			  fgets(texto, sizeof(texto), arquivoSequencialTextual);
			  //tratando texto
			  for(j=0;j<5001;j++){
			  	    if(texto[j]==10)//testa se chegou ao final do campo
					{
				  	 	nivel=0;
				  	 	texto_aux[k]='\0';//finaliza linha
				  	 	k=0;//zera o k para voltar ao inicio do vetor texto_aux na proxima leitura
				  	 	break;//para o loop
					}	
			  		if(nivel==1)
					{
					 	texto_aux[k]=texto[j];
					 	k++;
					}
			  		if(texto[j]=='=')//começa a ler a informacao do campo
					{
			  	 		nivel=1;
					}
					
			  }
			  strcpy(vet_consulta[i].item_consulta.descricao, texto_aux);
			  fscanf(arquivoSequencialTextual,"Novo_Valor=%f \n", &vet_consulta[i].item_consulta.novo_valor);
			  fscanf(arquivoSequencialTextual,"Valor_Custo=%f\n", &vet_consulta[i].item_consulta.valor_custo);
			  fscanf(arquivoSequencialTextual,"Valor_Auxiliar=%f\n", &vet_consulta[i].item_consulta.valor_auxiliar);
			  fscanf(arquivoSequencialTextual,"Porte=%d\n", &vet_consulta[i].item_consulta.porte);
			  fscanf(arquivoSequencialTextual,"Filme=%d\n", &vet_consulta[i].item_consulta.filme);
		}		
		fclose (arquivoSequencialTextual);
	//Pergunta o numero da consulta para pesquisar no vetor
		printf("\t\nInforme o numero da consulta:\n\n"); 
		func_gen_linhap();
		printf(">");
		scanf("%d", &resposta);
		func_gen_linhap();
		//inicia a pesquisa binaria
		//inicia as posicoes
		int pos_inicial=0;
		int pos_final=11;
		int pos_media=5;
		int verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou  
		while(pos_inicial<=pos_inicial)
		{
		 pos_media = (pos_inicial + pos_final) / 2;
		 if (resposta == vet_consulta[pos_media].numero_consulta)
		      {
		         verifica = 1;
		         i=pos_media;
		         break;
		      } 
		 else 
			 {
			 	if (resposta < vet_consulta[pos_media].numero_consulta)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(resposta > vet_consulta[pos_media].numero_consulta)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
		}//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item
		//escreve itens apos serem ordenados pelo seu Novo Valor    
		if(verifica==1)//mostra item
		{
			  	  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
				  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
				  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
				  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
				  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
				  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
				  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
				  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
				  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
				  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
				  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
				  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
				  func_gen_linhac(); 
				  printf("Valor Total: ");
				  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
				  printf("R$%0.2f\n",(vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo));
				  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
		}
		else
		{
			  	  printf("Consulta nao encontrada!\n");
		}
		func_gen_linhap();
		printf("\n\n\n");
		system("PAUSE");
}
void func_09_01_04_calcular_valor_com_desconto(){
	func_gen_titulo(" Menu Principal->ED-09->Calcular valor com desconto da consulta.",
		                " ",
		                "         -Le os dados do arquivo squencial textual.", 31,
		                "         -Pede a posicao do dado.",
		                "         -Calcula o valor com desconto da consulta e exibe em tela.");
		struct consulta vet_consulta[11];               
		int i,j,k;
		int nivel;
		int resposta;
		char texto[5001];//usado para uaxiliar na leitura de uma linha inteira
		char texto_aux[5001];
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		FILE *arquivoSequencialTextual = fopen("arquivo_sequencial_textual.txt", "r");
  		if (!arquivoSequencialTextual)//SE NAO, PERGUNTA SE QUER CRIAR
		{
			printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
			func_gen_linhap();
			printf(">");
			scanf("%d", &resposta);
			if (resposta==1)
			{
			    func_gen_limpa_tela();            
			    func_09_01_01_escrever_arquivo_textual();
			    return;
			}
		}
		j=0;//para correr o vetor texto
		k=0;//para correr o vetor texto_aux
		nivel=0;//nivel =o nao le a char, =1 le a char
		for(i=0;i<11;i++)
		{
			  fscanf(arquivoSequencialTextual,"Numero_da_Consulta=%d\n", &vet_consulta[i].numero_consulta);
			  //lendo a linha inteira
			  fgets(texto, sizeof(texto), arquivoSequencialTextual);
			  //tratando texto
			  for(j=0;j<5001;j++){
			  	    if(texto[j]==10)//testa se chegou ao final do campo
					{
				  	 	nivel=0;
				  	 	texto_aux[k]='\0';//finaliza linha
				  	 	k=0;//zera o k para voltar ao inicio do vetor texto_aux na proxima leitura
				  	 	break;//para o loop
					}	
			  		if(nivel==1)
					{
					 	texto_aux[k]=texto[j];
					 	k++;
					}
			  		if(texto[j]=='=')//começa a ler a informacao do campo
					{
			  	 		nivel=1;
					}
					
			  }
			  strcpy(vet_consulta[i].nome_paciente, texto_aux);
			  fscanf(arquivoSequencialTextual,"Dia=%d\n", &vet_consulta[i].data_consulta.dia);
			  fscanf(arquivoSequencialTextual,"Mes=%d\n", &vet_consulta[i].data_consulta.mes);
			  fscanf(arquivoSequencialTextual,"Ano=%d\n", &vet_consulta[i].data_consulta.ano);
			  fscanf(arquivoSequencialTextual,"Codigo=%d\n", &vet_consulta[i].item_consulta.codigo);
			  //lendo a linha inteira
			  fgets(texto, sizeof(texto), arquivoSequencialTextual);
			  //tratando texto
			  for(j=0;j<5001;j++){
			  	    if(texto[j]==10)//testa se chegou ao final do campo
					{
				  	 	nivel=0;
				  	 	texto_aux[k]='\0';//finaliza linha
				  	 	k=0;//zera o k para voltar ao inicio do vetor texto_aux na proxima leitura
				  	 	break;//para o loop
					}	
			  		if(nivel==1)
					{
					 	texto_aux[k]=texto[j];
					 	k++;
					}
			  		if(texto[j]=='=')//começa a ler a informacao do campo
					{
			  	 		nivel=1;
					}
					
			  }
			  strcpy(vet_consulta[i].item_consulta.descricao, texto_aux);
			  fscanf(arquivoSequencialTextual,"Novo_Valor=%f \n", &vet_consulta[i].item_consulta.novo_valor);
			  fscanf(arquivoSequencialTextual,"Valor_Custo=%f\n", &vet_consulta[i].item_consulta.valor_custo);
			  fscanf(arquivoSequencialTextual,"Valor_Auxiliar=%f\n", &vet_consulta[i].item_consulta.valor_auxiliar);
			  fscanf(arquivoSequencialTextual,"Porte=%d\n", &vet_consulta[i].item_consulta.porte);
			  fscanf(arquivoSequencialTextual,"Filme=%d\n", &vet_consulta[i].item_consulta.filme);
		}		
		fclose (arquivoSequencialTextual);
	//Pergunta o numero da consulta para pesquisar no vetor
		printf("\t\nInforme o numero da consulta:\n\n"); 
		func_gen_linhap();
		printf(">");
		scanf("%d", &resposta);
		func_gen_linhap();
		//inicia a pesquisa binaria
		//inicia as posicoes
		int pos_inicial=0;
		int pos_final=11;
		int pos_media=5;
		int verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou  
		while(pos_inicial<=pos_inicial)
		{
		 pos_media = (pos_inicial + pos_final) / 2;
		 if (resposta == vet_consulta[pos_media].numero_consulta)
		      {
		         verifica = 1;
		         i=pos_media;
		         break;
		      } 
		 else 
			 {
			 	if (resposta < vet_consulta[pos_media].numero_consulta)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(resposta > vet_consulta[pos_media].numero_consulta)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
		}//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item
		//escreve itens apos serem ordenados pelo seu Novo Valor    
		if(verifica==1)//mostra item
		{
			  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
			  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
			  func_gen_linhac();
			  printf("Valor Total       : ");
			  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			  printf("R$%0.2f\n",(vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo));
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Valor com desconto: ");
			  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			  printf("R$%0.2f\n",((vet_consulta[i].item_consulta.novo_valor+vet_consulta[i].item_consulta.valor_custo)-vet_consulta[i].item_consulta.valor_auxiliar));
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
		}
		else
		{
			  printf("Consulta nao encontrada!\n");
		}
		func_gen_linhap();
		printf("\n\n\n");
		system("PAUSE");
	
}
void func_09_01_05_TAD_09(){
	func_gen_titulo(" Menu Principal->ED-09->TAD-09",
                    " ",
                    "                                                    TAD-09", 31,
                    "                                         ESPECIFICACAO DAS FUNCOES DO TAD-09",
                    " ");
      printf("\n\t A TAD-09 teve como objetivo Manipular um arquivo sequencial textual.\n");
	  printf("\n Nessa Atividade, implementamos 4 funcoes como descrito abaixo:\n");
      printf("\n\t (1) - func_09_01_01_escrever_arquivo_textual()\n");
      printf("\n\t (2) - func_09_01_02_ler_arquivo_textual()\n");
      printf("\n\t (3) - func_09_01_03_calcular_valor_total()\n");
      printf("\n\t (4) - func_09_01_02_ler_arquivo_textual()\n");
      printf("\n\t (1) - Essa funcao tem como objetivo ler dados de 11 consultas do arquivo XML que estao presentes no ED-07 e escrevelos em um arquivo sequencial textual.\n");
      printf("\n\t (2) - Essa funcao tem como objetivo ler o arquivo sequencial textual de campos com tamnhos variaveis e escrever todos esses dados de maneira organizada em tela.\n");
	  printf("\n\t (3) - Essa funcao ler os dados do arquivo textual sequencial, pede ao usuario um numero de consulta e pesquisa no vetor de consultas o campo procurado e logo depois calcula o valor total da consulta e exibe em tela.\n");
	  printf("\n\t (4) - Como a funcao anterior, essa funcao ler os dados do arquivo textual e exibe o dados escolhido pelo usuario em tela mostrando o valor da consulta com desconto.\n");
	  
	  printf("\n\t Como no TAD-07 e no TAD-08 tambem utilizou as estruturas listadas abaixo e um vetor de estrutura do tipo consulta.");
	  printf("\t\nVariaveis:\n\n");
	  printf("\t(1)     struct item{ int codigo;\n");
	  printf("\t                     char descricao[5000]; \n");
	  printf("\t                     float novo_valor;\n");
	  printf("\t                     float valor_custo;\n");
	  printf("\t                     float valor_auxiliar;\n");
	  printf("\t                     int porte;\n");
	  printf("\t                     int filme;};\n");
	  printf("\t(2)     struct data{ int ano;\n");
	  printf("\t                     int dia; \n");
	  printf("\t                     int mes;};\n");
	  printf("\t(3) struct consulta{ int numero_consulta;\n");
	  printf("\t                     char nome_paciente[5000];\n");
	  printf("\t                     struct data data_consulta;\n");
	  printf("\t                     struct item item_consulta;;};\n");
	  printf("\t(4)struct consulta vet_consulta[11];\n");
	  printf("\t(5)char texto[5001];\n");
	  printf("\t(6)char texto_aux[5001];\n");
      printf("\n\n\n");
      printf("-Explicacao Para Variavel (1)\n *Struct item, que contem todos os campos de uma linha da tabela TUSS. Essa struct foi criada para auxiliar na manipulacao de linhas da tabela TUSS da unimed de Maringa.\n\n");
      printf("-Explicacao Para Variavel (2)\n *Struct data, Essa struct possui os campos dia, me e ano, do tipo inteiro e foi criada apenas para armazenar a data da consulta na (3)struct consulta.\n\n");
      printf("-Explicacao Para Variavel (3)\n *Struct consulta, Essa struct possui todos os campos da tag consulta que esta no arquivo XML. Sendo eles: numero da consulta do tipo int, nome_paciente do tipo char[], data_consulta do tipo struct data e item_consulta do tipo struct item. Essa struct foi criada para fazer possivel a modelagem da tag consulta presente no arquivo XML na TAD-07.\n\n");
      printf("-Explicacao Para Variavel (4)\n *Vetor de structs consulta. Esse vetor foi criado para organizar todas os dados continos na tag consulta do arquivo XML. Por haver tambem a necessidade de fazer uma pesquisa binaria, esse vetor facilitou a realizacao da pesquisa binaria nas funcoes 3 e 4. Lembrando que na hora de ler os campos nome e descricao do procedimento do arquivo de texto, se faz necessario o tratamento da linha lida, pois o programa precisa ler toda a linha do arquivo e retirar a descricao do campo para so entao atribuir o texto do campo lido a struct.\n\n");
	  printf("-Explicacao Para Variavel (5)\n *Vetor de char utilizado para ler uma linha do arquivo textual que contem campos de texto.\n\n");
	  printf("-Explicacao Para Variavel (6)\n *Vetor de char utilizado para fazer o tratamento da linha lida em campos do tipo texto no arquivo textual. Sao esses campos o nome do paciente e a descricao do procedimento realizado pelo paciente. O programa percorre a descricao do campo ate achar o sinal de = e so entao comeca a copiar a sequencia de char para a variaval texto_aux, faz isso ate achar uma quebra de linha.\n\n");
	  
	  system("PAUSE");
}
void func_10_01_01_escrever_arquivo_binario(){
	    func_gen_titulo(" Menu Principal->ED-10->Escrever arquivos binarios (Tanto o de dados como o de indice).",
		                " ",
		                " Le os dados do arquivo XML presente na ED-07,", 31,
		                " escreve um arquivo binario com os dados e o arquivo de indice ordenado pelo numero da consulta.",
		                " ");
		struct consulta vet_consulta[11];
		struct indice_consulta index[11];          
		int i;
		int NRR;
		int resposta;
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//passa o  vetor de consulta por parametro para a funcao ler as consultas (vet_consulta, tamanho)  
		func_gen_ler_vetor_consultas(vet_consulta, 11);
		//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
		if(vet_consulta[1].numero_consulta==-1)
		{
			return;
		}
		FILE *arquivoBinarioConsultas = fopen("arquivo_binario_consultas.bin", "wb");
		FILE *arquivoBinarioIndiceConsultas = fopen("arquivo_binario_indice_consultas.bin", "wb");
		fwrite(vet_consulta,sizeof(struct consulta),11,arquivoBinarioConsultas);
		//construindo o vetor de indeces de consultas
		for(i=0;i<11;i++)
		{
			index[i].numero_consulta=vet_consulta[i].numero_consulta;
			NRR=i+1;
			index[i].NRR=NRR;	
		}
		fwrite(index,sizeof(struct indice_consulta),11,arquivoBinarioIndiceConsultas);
		fclose(arquivoBinarioConsultas);//fecha os arquivo que foram abertos para escrita.
		fclose(arquivoBinarioIndiceConsultas);
		printf("\n\n\n\t->arquivo_binario_consultas.bin\n");
		printf("\t->arquivo_binario_indice_consultas.bin\n\n");
		printf("\tArquivo binario e indice escritos com sucesso!\n\n\n\n");
		func_gen_linhap();
		printf(">");
		system("PAUSE");
}
void func_10_01_02_ler_arquivo_binario(){
		func_gen_titulo(" Menu Principal->ED-10->Visualizar todo arquivo binario.",
	                    " ",
	                    " -Lendo todo conteudo do arquivo de nome arquivo_binario_consultas.bin e exibindo", 31,
	                    "  os dados de maneira organizada em tela.",
	                    " ");
		struct consulta vet_consulta[11]; 
		int resposta;
		int i;    
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                                   
		FILE *arquivo_binario = fopen("arquivo_binario_consultas.bin", "rb");
		if (!arquivo_binario)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		fread(vet_consulta,sizeof(struct consulta),11,arquivo_binario);//leu todas as structs do tipo consulta e colocou no vetor consulta
		printf("Dados de consultas lidos do arquivo binario, arquivo_binario_consultas.bin, e exibidos em tela:.\n");
		func_gen_linhap();
		for(i=0;i<11;i++)
		{
			  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
			  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
			  func_gen_linhac(); 
		}
		printf("\n\n\n");
		system("PAUSE");
}
void func_10_01_03_ler_indice(){
	    func_gen_titulo(" Menu Principal->ED-10->Visualizar todo o indice.",
	                    " ",
	                    " -Lendo todo conteudo do arquivo de nome arquivo_binario_indice_consultas.bin e exibindo", 31,
	                    "  os dados de maneira organizada em tela.",
	                    " ");
		struct indice_consulta index[11]; 
		int resposta;
		int i;    
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                                   
		FILE *arquivo_binario = fopen("arquivo_binario_indice_consultas.bin", "rb");
		if (!arquivo_binario)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		fread(index,sizeof(struct indice_consulta),11,arquivo_binario);//leu todas as structs do tipo consulta e colocou no vetor consulta
		printf("Exibindo o Indice do arquivo binario, arquivo_binario_indice_consultas.bin\n");
		func_gen_linhap();
		printf("\n\n\t");
		SetConsoleTextAttribute(hConsole, 55);
		printf("  Arquivo de Indice \n");
		SetConsoleTextAttribute(hConsole, 240);
		printf("\t");
		SetConsoleTextAttribute(hConsole, 7);
		printf("  Numero      NRR   \n");
		SetConsoleTextAttribute(hConsole, 240);
		for(i=0;i<11;i++)
		{
			  printf("\t");
			  SetConsoleTextAttribute(hConsole, 135);
			  printf("    %-6d", index[i].numero_consulta);
			  SetConsoleTextAttribute(hConsole, 120);
			  printf("    %-6d", index[i].NRR);
			  SetConsoleTextAttribute(hConsole, 240);
			  printf("\n");
			  
		}
		printf("\n\n");
		func_gen_linhap(); 
		printf("\n\n\n");
		system("PAUSE");
		
}
void func_10_01_04_consultar_usando_indice(){
	    func_gen_titulo(" Menu Principal->ED-10->Consultar arquivo binario utilizando o indice.",
	                    " ",
	                    " -Lendo conteudo do arquivo de nome arquivo_binario_consultas.bin utlizando", 31,
	                    "  o indice que esta gravano no arquivo arquivo_binario_indice_consultas.bin",
	                    " ");
		struct indice_consulta index[11];
		struct consulta consulta_lida;
		int resposta;
		int i;    
		int NRR;
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                                   
		FILE *arquivo_binario = fopen("arquivo_binario_indice_consultas.bin", "rb");
		FILE *arquivo_binario_consulta = fopen("arquivo_binario_consultas.bin", "rb");
		if (!arquivo_binario)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		fread(index,sizeof(struct indice_consulta),11,arquivo_binario);//leu todas as structs do tipo consulta e colocou no vetor consulta
		//Pergunta o numero da consulta para pesquisar no vetor
		printf("\t\nInforme o numero da consulta:\n\n"); 
		func_gen_linhap();
		printf(">");
		scanf("%d", &resposta);
		func_gen_linhap();
		//inicia a pesquisa binaria
		//inicia as posicoes
		int pos_inicial=0;
		int pos_final=11;
		int pos_media=5;
		int verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou  
		while(pos_inicial<=pos_inicial)
		{
		 pos_media = (pos_inicial + pos_final) / 2;
		 if (resposta == index[pos_media].numero_consulta)
		      {
		         verifica = 1;
		         i=pos_media;
		         break;
		      } 
		 else 
			 {
			 	if (resposta < index[pos_media].numero_consulta)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(resposta > index[pos_media].numero_consulta)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
		}//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item
		//Pega a NRR do dado procurado no indice caso encontrado e vai para o arquivo ler o dado.
		if(verifica==1)//mostra item
		{
			NRR=index[i].NRR;
			fseek(arquivo_binario_consulta,((NRR-1)*sizeof(consulta)),SEEK_SET);//vai ate a posicao da consulta medica a ser lida
			fread(&consulta_lida,sizeof(struct consulta),1,arquivo_binario_consulta);
			//Escreve indice lido na tela:
			printf("\n\t");
			SetConsoleTextAttribute(hConsole, 55);
			printf("  Arquivo de Indice \n");
			SetConsoleTextAttribute(hConsole, 240);
			printf("\t");
			SetConsoleTextAttribute(hConsole, 7);
			printf("  Numero      NRR   \n");
			SetConsoleTextAttribute(hConsole, 240);
			printf("\t");
			SetConsoleTextAttribute(hConsole, 135);
			printf("    %-6d", index[i].numero_consulta);
			SetConsoleTextAttribute(hConsole, 120);
			printf("    %-6d", index[i].NRR);
			SetConsoleTextAttribute(hConsole, 240);
			printf("\n\n");
			func_gen_linhac();
			//Escreve consulta lida do arquivo arquivo_binario_consultas.bin
			printf("Numero da Consulta: %d\n", consulta_lida.numero_consulta);
			printf("Nome do Paciente  : %s\n", consulta_lida.nome_paciente);
			printf("Data da Consulta  : %d/%d/%d\n", consulta_lida.data_consulta.dia,consulta_lida.data_consulta.mes,consulta_lida.data_consulta.ano);
			SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("Codigo            : %d\n", consulta_lida.item_consulta.codigo);
			printf("Descricao         : %s\n", consulta_lida.item_consulta.descricao);
			printf("Novo Valor        : R$%0.2f \n", consulta_lida.item_consulta.novo_valor);
			printf("Valor Custo       : R$%0.2f\n", consulta_lida.item_consulta.valor_custo);
			printf("Valor Auxiliar    : R$%0.2f\n", consulta_lida.item_consulta.valor_auxiliar);
			printf("Porte             : %d\n", consulta_lida.item_consulta.porte);
			printf("Filme             : %d\n", consulta_lida.item_consulta.filme);
			func_gen_linhap(); 
		}
		else
		{
		    printf("\n\n\tValor nao encontrado no indice!\n\n\n");
		    func_gen_linhap();
		}
		
		system("PAUSE");
		
}
void func_10_01_05_valor_total()
{
	func_gen_titulo(" Menu Principal->ED-10->Calcular valor total de consulta.",
	                    " ",
	                    " -Lendo conteudo do arquivo de nome arquivo_binario_consultas.bin utlizando", 31,
	                    "  o indice que esta gravano no arquivo arquivo_binario_indice_consultas.bin,",
	                    "  calculando o valor total da consulta e Exibindo em tela.");
		struct indice_consulta index[11];
		struct consulta consulta_lida;
		int resposta;
		int i;    
		int NRR;
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                                   
		FILE *arquivo_binario = fopen("arquivo_binario_indice_consultas.bin", "rb");
		FILE *arquivo_binario_consulta = fopen("arquivo_binario_consultas.bin", "rb");
		if (!arquivo_binario)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		fread(index,sizeof(struct indice_consulta),11,arquivo_binario);//leu todas as structs do tipo consulta e colocou no vetor consulta
		//Pergunta o numero da consulta para pesquisar no vetor
		printf("\t\nInforme o numero da consulta:\n\n"); 
		func_gen_linhap();
		printf(">");
		scanf("%d", &resposta);
		func_gen_linhap();
		//inicia a pesquisa binaria
		//inicia as posicoes
		int pos_inicial=0;
		int pos_final=11;
		int pos_media=5;
		int verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou  
		while(pos_inicial<=pos_inicial)
		{
		 pos_media = (pos_inicial + pos_final) / 2;
		 if (resposta == index[pos_media].numero_consulta)
		      {
		         verifica = 1;
		         i=pos_media;
		         break;
		      } 
		 else 
			 {
			 	if (resposta < index[pos_media].numero_consulta)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(resposta > index[pos_media].numero_consulta)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
		}//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item
		//Pega a NRR do dado procurado no indice caso encontrado e vai para o arquivo ler o dado.
		if(verifica==1)//mostra item
		{
			NRR=index[i].NRR;
			fseek(arquivo_binario_consulta,((NRR-1)*sizeof(consulta)),SEEK_SET);//vai ate a posicao da consulta medica a ser lida
			fread(&consulta_lida,sizeof(struct consulta),1,arquivo_binario_consulta);
			//Escreve indice lido na tela:
			printf("\n\t");
			SetConsoleTextAttribute(hConsole, 55);
			printf("  Arquivo de Indice \n");
			SetConsoleTextAttribute(hConsole, 240);
			printf("\t");
			SetConsoleTextAttribute(hConsole, 7);
			printf("  Numero      NRR   \n");
			SetConsoleTextAttribute(hConsole, 240);
			printf("\t");
			SetConsoleTextAttribute(hConsole, 135);
			printf("    %-6d", index[i].numero_consulta);
			SetConsoleTextAttribute(hConsole, 120);
			printf("    %-6d", index[i].NRR);
			SetConsoleTextAttribute(hConsole, 240);
			printf("\n\n");
			func_gen_linhac();
			//Escreve consulta lida do arquivo arquivo_binario_consultas.bin
			printf("Numero da Consulta: %d\n", consulta_lida.numero_consulta);
			printf("Nome do Paciente  : %s\n", consulta_lida.nome_paciente);
			printf("Data da Consulta  : %d/%d/%d\n", consulta_lida.data_consulta.dia,consulta_lida.data_consulta.mes,consulta_lida.data_consulta.ano);
			SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("Codigo            : %d\n", consulta_lida.item_consulta.codigo);
			printf("Descricao         : %s\n", consulta_lida.item_consulta.descricao);
			printf("Novo Valor        : R$%0.2f \n", consulta_lida.item_consulta.novo_valor);
			printf("Valor Custo       : R$%0.2f\n", consulta_lida.item_consulta.valor_custo);
			printf("Valor Auxiliar    : R$%0.2f\n", consulta_lida.item_consulta.valor_auxiliar);
			printf("Porte             : %d\n", consulta_lida.item_consulta.porte);
			printf("Filme             : %d\n", consulta_lida.item_consulta.filme);
			func_gen_linhac(); 
			printf("Valor Total: ");
			SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			printf("R$%0.2f\n",(consulta_lida.item_consulta.novo_valor+consulta_lida.item_consulta.valor_custo));
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			func_gen_linhap(); 
		}
		else
		{
		    printf("\n\n\tValor nao encontrado no indice!\n\n\n");
		    func_gen_linhap();
		}
		
		system("PAUSE");
}
void func_10_01_06_valor_com_desconto()
{
		func_gen_titulo(" Menu Principal->ED-10->Calcular valor com desconto de consulta.",
	                    " ",
	                    " -Lendo conteudo do arquivo de nome arquivo_binario_consultas.bin utlizando", 31,
	                    "  o indice que esta gravano no arquivo arquivo_binario_indice_consultas.bin,",
	                    "  calculando o valor com desconto da consulta e Exibindo em tela.");
		struct indice_consulta index[11];
		struct consulta consulta_lida;
		int resposta;
		int i;    
		int NRR;
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                                   
		FILE *arquivo_binario = fopen("arquivo_binario_indice_consultas.bin", "rb");
		FILE *arquivo_binario_consulta = fopen("arquivo_binario_consultas.bin", "rb");
		if (!arquivo_binario)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		fread(index,sizeof(struct indice_consulta),11,arquivo_binario);//leu todas as structs do tipo consulta e colocou no vetor consulta
		//Pergunta o numero da consulta para pesquisar no vetor
		printf("\t\nInforme o numero da consulta:\n\n"); 
		func_gen_linhap();
		printf(">");
		scanf("%d", &resposta);
		func_gen_linhap();
		//inicia a pesquisa binaria
		//inicia as posicoes
		int pos_inicial=0;
		int pos_final=11;
		int pos_media=5;
		int verifica=0;//inicia sequencia com verificacao igual a zero indicando que nao achou  
		while(pos_inicial<=pos_inicial)
		{
		 pos_media = (pos_inicial + pos_final) / 2;
		 if (resposta == index[pos_media].numero_consulta)
		      {
		         verifica = 1;
		         i=pos_media;
		         break;
		      } 
		 else 
			 {
			 	if (resposta < index[pos_media].numero_consulta)
			          {
			             pos_final = pos_media - 1;
			             //continue;
			          }
			      else 
				      {
				      	if(resposta > index[pos_media].numero_consulta)
				          {
				             pos_inicial = pos_media + 1;
				             //continue;
				          }
				          else
				          {
				             verifica = 0;
				             break;
				          }		  
					  }  
			 }	  
			 if(pos_media==pos_inicial || pos_media==pos_final)
			  	 {
			  	 	break;
				 }
		}//faz o processo de busca enquanto nao achar nada ou ate descobrir que nao existe o item
		//Pega a NRR do dado procurado no indice caso encontrado e vai para o arquivo ler o dado.
		if(verifica==1)//mostra item
		{
			NRR=index[i].NRR;
			fseek(arquivo_binario_consulta,((NRR-1)*sizeof(consulta)),SEEK_SET);//vai ate a posicao da consulta medica a ser lida
			fread(&consulta_lida,sizeof(struct consulta),1,arquivo_binario_consulta);
			//Escreve indice lido na tela:
			printf("\n\t");
			SetConsoleTextAttribute(hConsole, 55);
			printf("  Arquivo de Indice \n");
			SetConsoleTextAttribute(hConsole, 240);
			printf("\t");
			SetConsoleTextAttribute(hConsole, 7);
			printf("  Numero      NRR   \n");
			SetConsoleTextAttribute(hConsole, 240);
			printf("\t");
			SetConsoleTextAttribute(hConsole, 135);
			printf("    %-6d", index[i].numero_consulta);
			SetConsoleTextAttribute(hConsole, 120);
			printf("    %-6d", index[i].NRR);
			SetConsoleTextAttribute(hConsole, 240);
			printf("\n\n");
			func_gen_linhac();
			//Escreve consulta lida do arquivo arquivo_binario_consultas.bin
			printf("Numero da Consulta: %d\n", consulta_lida.numero_consulta);
			printf("Nome do Paciente  : %s\n", consulta_lida.nome_paciente);
			printf("Data da Consulta  : %d/%d/%d\n", consulta_lida.data_consulta.dia,consulta_lida.data_consulta.mes,consulta_lida.data_consulta.ano);
			SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("Codigo            : %d\n", consulta_lida.item_consulta.codigo);
			printf("Descricao         : %s\n", consulta_lida.item_consulta.descricao);
			printf("Novo Valor        : R$%0.2f \n", consulta_lida.item_consulta.novo_valor);
			printf("Valor Custo       : R$%0.2f\n", consulta_lida.item_consulta.valor_custo);
			printf("Valor Auxiliar    : R$%0.2f\n", consulta_lida.item_consulta.valor_auxiliar);
			printf("Porte             : %d\n", consulta_lida.item_consulta.porte);
			printf("Filme             : %d\n", consulta_lida.item_consulta.filme);
			func_gen_linhac();
			printf("Valor Total       : ");
			SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			printf("R$%0.2f\n",(consulta_lida.item_consulta.novo_valor+consulta_lida.item_consulta.valor_custo));
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("Valor com desconto: ");
			SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			printf("R$%0.2f\n",((consulta_lida.item_consulta.novo_valor+consulta_lida.item_consulta.valor_custo)-consulta_lida.item_consulta.valor_auxiliar));
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			func_gen_linhap(); 
		}
		else
		{
		    printf("\n\n\tValor nao encontrado no indice!\n\n\n");
		    func_gen_linhap();
		}
		
		system("PAUSE");
	
}
void func_10_01_07_TAD_10(){
		func_gen_titulo(" Menu Principal->ED-10->TAD-10",
                    " ",
                    "                                                    TAD-10", 31,
                    "                                         ESPECIFICACAO DAS FUNCOES DO TAD-10",
                    " ");
		printf("\n\t A TAD-10 teve como objetivo Manipular um arquivo binario.\n");
		printf("\n Nessa Atividade, implementamos 6 funcoes como descrito abaixo:\n");
		printf("\t (1) - func_10_01_01_escrever_arquivo_binario()\n");
		printf("\t (2) - func_10_01_02_ler_arquivo_binario()\n");
		printf("\t (3) - func_10_01_03_ler_indice()\n");
		printf("\t (4) - func_10_01_04_consultar_usando_indice()\n");
		printf("\t (5) - func_10_01_05_valor_total()\n");
		printf("\t (6) - func_10_01_06_valor_com_desconto()\n\n");
		
		
		printf("\t (1) - Essa funcao tem como objetivo ler os dados do arquivo XML e escreve em um arquivo binario.\n");
		printf("\t (2) - Essa funcao le o arquivo binario que contem os dados de todas as consultas e os exibe na integra em tela\n");
		printf("\t (3) - Funcao criada para o usuario visualizar o arquivo de indice referente ao arquivo de consultas medicas.\n");
		printf("\t (4) - Essa funcao permite ao usuario fazer uma busca no arquivo binario de consultas medicas utilizando o arquivo de indice, que por sua vez tem os campos numero da consulta e NRR do dado.\n");
		printf("\t (5) - Essa funcao faz uma busca binaria no arquivo de indice pelo numero da consulta e utiliza o respectivo NRR para acessar o arquivo de consultas utilizando a funcao fseek para posicionar o curso exatamnte no dado que foi pesquisado. Evitando assim a leitura completa do arquivo que contem todos os dados das consultas medicas. Entao calcula o valor total da consulta e exibe os dados em tela.\n");
		printf("\t (6) - Faz o mesmo que a funcao 5, porem calcula o valor com desconto da consulta.\n");
		
		printf("\n\t Estruturas e variaveis utilizadas nesta TAD.\n");
		printf("\t\nVariaveis:\n\n");
		printf("\t(1) struct consulta{ int numero_consulta;\n");
		printf("\t                     char nome_paciente[5000];\n");
		printf("\t                     struct data data_consulta;\n");
		printf("\t                     struct item item_consulta;}\n");
	    printf("\t(2) struct indice_consulta{\n");
    	printf("\t                           int numero_consulta;\n");
    	printf("\t                           int NRR;\n");
	    printf("\t                          }\n");
		printf("\t(3)struct consulta vet_consulta[11]\n");
		printf("\t(4)struct indice_consulta index[11]\n"); 
		printf("\t(5)struct consulta consulta_lida\n");
		printf("\n\n\n");
		printf("  -Explicacao Para Variavel (1)\n  *Struct do tipo consulta, foi criada para arganizar todos os dados de um consulta medica contido nos arquivos. Ela possui diversos campos como ja foi cidade em TADs anteriores ou como ser visto na descricao dela logo acima.\n");
		printf("  -Explicacao Para Variavel (2)\n  *Essa struct foi criada para modelar cada linha do arquivo de indice. Como o indice foi feito utilizando o numero da consulta, essa struct possui os campos numero_consulta, para armazenar o numero da consulta e o campo NRR, servido para armazenar a posicao dos dados referente a consulta do respectivo numero no arquivo binario arquivo_binario_consultas.bin.\n");
		printf("  -Explicacao Para Variavel (3)\n  *Esse vetor de structs consulta e utilizado para armazenar as consultas medicas lidas do arquivo XML e tambem e usado para escrever todas as consulta no arquivo binario arquivo_binario_consultas.bin.\n");
		printf("  -Explicacao Para Variavel (4)\n  *Vetor de struturas do tipo indice_consulta, esse vetor serve para auxiliar na criacao do indice, na funcao 1, quando e criado o arquivo com os dados, tambem e atribuido a esse vetor do tipo indice o dado numero da consulta que e utilizado como chave para cada consulta registrada e logo depois e atribuido a recorrente posicao desse vetor o NRR em que o dado esta sendo gravado. Assim temos um vetor de indice onde eh correlacionado o numero da consulta e o NRR dela no arquivo, facilitando o acesso ao arquivo com os dados utilizando a funcao fseek e lendo somente os dados de interesse.\n");
		printf("  -Explicacao Para Variavel (5)\n  *Essa struct foi instanciada para receber a struct que o usuario procurou no indice e foi ao arquivo ler. Tambem e utilizada para exibir os dados da consulta medica lida em tela.\n\n\n");
		system("PAUSE");
}
void func_11_01_02_visualizar_bloco(){
		func_gen_titulo(" Menu Principal->ED-11->Visualizar todo o bloco de consultas.",
	                    " ",
	                    " Alocando um endereco de memoria para uma variavel do tipo bloco_consultas, ", 31,
	                    " lendo consulta por consulta do arquivo binario com o comando fred e preenchendo",
	                    " via ponteiro o campo vetorConsultas da estrutura bloco_consultas utilizando um laco for.");
	    int resposta, NRR, i;
	    HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
	    FILE *arquivo_binario_consulta = fopen("arquivo_binario_consultas.bin", "rb");
		struct bloco_consulta *p_bloco;
		p_bloco = (struct bloco_consulta *) malloc(sizeof(struct bloco_consulta));//aloca memoria para um bloco de consulta e coloca o endereco alocado em p_bloco         
	    //primeiro testa se o arquivo binario existe se nao pergunta se quer criar		
		if (!arquivo_binario_consulta)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		//Lendo primeiro campo de consulta medica no arquivo binario e atribuindo via ponteiro ao campo vetorConsultas da struct bloco_consulta
		for(NRR=1;NRR<12;NRR++){ // corre o nrr de 1 a 11
			fseek(arquivo_binario_consulta,((NRR-1)*sizeof(struct consulta)),SEEK_SET);//vai ate a posicao da consulta medica a ser lida
			fread((*p_bloco).vetorConsultas+(NRR-1),sizeof(struct consulta),1,arquivo_binario_consulta); //NRR-1 para colocar na posicao de memoria certa pois o NRR e a posicao do dado no arquivo q comeca em 1
		}
		strcpy((*p_bloco).titulo,"Bloco de consultas realizadas pela UNIMED MARINGA.");                
		printf("%s\n",(*p_bloco).titulo);
		func_gen_linhap();
		for(i=0;i<11;i++)
		{
			  printf("Numero da Consulta: %d\n", (*p_bloco).vetorConsultas[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", (*((*p_bloco).vetorConsultas+i)).nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", (*p_bloco).vetorConsultas[i].data_consulta.dia,(*p_bloco).vetorConsultas[i].data_consulta.mes,(*p_bloco).vetorConsultas[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", (*p_bloco).vetorConsultas[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", (*p_bloco).vetorConsultas[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.porte);
			  printf("Filme             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.filme);
			  func_gen_linhac(); 
		}
		printf("\n\n\n"); 
	    system("PAUSE");
}
void func_11_01_03_zerar_vauxiliar(){
		func_gen_titulo(" Menu Principal->ED-11->Zerar valor auxiliar das consultas.",
	                    " Alocando um endereco de memoria para uma variavel do tipo bloco_consultas, ",
	                    " lendo consulta por consulta do arquivo binario com o comando fred e preenchendo", 31,
	                    " via ponteiro o campo vetorConsultas da estrutura bloco_consultas utilizando um laco for.",
	                    " Apos esse procedimento, corre os campos consulta via ponteiro alterando o valor auxiliar para 0.");
	    int resposta, NRR, i;
	    HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
	    FILE *arquivo_binario_consulta = fopen("arquivo_binario_consultas.bin", "rb");
		struct bloco_consulta *p_bloco;
		p_bloco = (struct bloco_consulta *) malloc(sizeof(struct bloco_consulta));//aloca memoria para um bloco de consulta e coloca o endereco alocado em p_bloco         
	    //primeiro testa se o arquivo binario existe se nao pergunta se quer criar		
		if (!arquivo_binario_consulta)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		//Lendo primeiro campo de consulta medica no arquivo binario e atribuindo via ponteiro ao campo vetorConsultas da struct bloco_consulta
		for(NRR=1;NRR<12;NRR++){ // corre o nrr de 1 a 11
			fseek(arquivo_binario_consulta,((NRR-1)*sizeof(struct consulta)),SEEK_SET);//vai ate a posicao da consulta medica a ser lida
			fread((*p_bloco).vetorConsultas+(NRR-1),sizeof(struct consulta),1,arquivo_binario_consulta); //NRR-1 para colocar na posicao de memoria certa pois o NRR e a posicao do dado no arquivo q comeca em 1
		}
		strcpy((*p_bloco).titulo,"Bloco de consultas realizadas pela UNIMED MARINGA.");
		//corre toda as consultas por ponteiro zerando o valor auxiliar
	    for(i=0;i<11;i++){
			(*p_bloco).vetorConsultas[i].item_consulta.valor_auxiliar=0.0;
			//Outra possibilidade de correr o endereco de memoria estaticmente alocado
			//(*((*p_bloco).vetorConsultas+i)).item_consulta.valor_auxiliar=0.0;
		}            
		printf("%s\n",(*p_bloco).titulo);
		func_gen_linhap();
		for(i=0;i<11;i++)
		{
			  printf("Numero da Consulta: %d\n", (*p_bloco).vetorConsultas[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", (*((*p_bloco).vetorConsultas+i)).nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", (*p_bloco).vetorConsultas[i].data_consulta.dia,(*p_bloco).vetorConsultas[i].data_consulta.mes,(*p_bloco).vetorConsultas[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", (*p_bloco).vetorConsultas[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", (*p_bloco).vetorConsultas[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_custo);
			  SetConsoleTextAttribute(hConsole, 124);//retorna ao padrao de cor normal
			  printf("Valor Auxiliar    : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_auxiliar);
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Porte             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.porte);
			  printf("Filme             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.filme);
			  func_gen_linhac(); 
		}
		printf("\n\n\n"); 
	    system("PAUSE");	
}
void func_11_01_04_esconder_nome(){
		func_gen_titulo(" Menu Principal->ED-11->Esconder nome do paciente das consultas.",
	                    " Alocando um endereco de memoria para uma variavel do tipo bloco_consultas, ",
	                    " lendo consulta por consulta do arquivo binario com o comando fred e preenchendo", 31,
	                    " via ponteiro o campo vetorConsultas da estrutura bloco_consultas utilizando um laco for.",
	                    " Apos esse procedimento, corre os campos consulta via ponteiro alterando o nome do paciente para ******.");
	    int resposta, NRR, i;
	    HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
	    FILE *arquivo_binario_consulta = fopen("arquivo_binario_consultas.bin", "rb");
		struct bloco_consulta *p_bloco;
		p_bloco = (struct bloco_consulta *) malloc(sizeof(struct bloco_consulta));//aloca memoria para um bloco de consulta e coloca o endereco alocado em p_bloco         
	    //primeiro testa se o arquivo binario existe se nao pergunta se quer criar		
		if (!arquivo_binario_consulta)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		//Lendo primeiro campo de consulta medica no arquivo binario e atribuindo via ponteiro ao campo vetorConsultas da struct bloco_consulta
		for(NRR=1;NRR<12;NRR++){ // corre o nrr de 1 a 11
			fseek(arquivo_binario_consulta,((NRR-1)*sizeof(struct consulta)),SEEK_SET);//vai ate a posicao da consulta medica a ser lida
			fread((*p_bloco).vetorConsultas+(NRR-1),sizeof(struct consulta),1,arquivo_binario_consulta); //NRR-1 para colocar na posicao de memoria certa pois o NRR e a posicao do dado no arquivo q comeca em 1
		}
		strcpy((*p_bloco).titulo,"Bloco de consultas realizadas pela UNIMED MARINGA.");
		//corre toda as consultas por ponteiro zerando o valor auxiliar
	    for(i=0;i<11;i++){
			strcpy((*((*p_bloco).vetorConsultas+i)).nome_paciente,"******");
		}            
		printf("%s\n",(*p_bloco).titulo);
		func_gen_linhap();
		for(i=0;i<11;i++)
		{
			  printf("Numero da Consulta: %d\n", (*p_bloco).vetorConsultas[i].numero_consulta);
			  SetConsoleTextAttribute(hConsole, 124);//retorna ao padrao de cor normal
			  printf("Nome do Paciente  : %s\n", (*((*p_bloco).vetorConsultas+i)).nome_paciente);
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Data da Consulta  : %d/%d/%d\n", (*p_bloco).vetorConsultas[i].data_consulta.dia,(*p_bloco).vetorConsultas[i].data_consulta.mes,(*p_bloco).vetorConsultas[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", (*p_bloco).vetorConsultas[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", (*p_bloco).vetorConsultas[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.porte);
			  printf("Filme             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.filme);
			  func_gen_linhac(); 
		}
		printf("\n\n\n"); 
	    system("PAUSE");
	
}
void func_11_01_05_valor_total(){
			func_gen_titulo(" Menu Principal->ED-11->Calcular valor total da consulta.",
	                    " Alocando um endereco de memoria para uma variavel do tipo bloco_consultas, ",
	                    " lendo consulta por consulta do arquivo binario com o comando fred e preenchendo", 31,
	                    " via ponteiro o campo vetorConsultas da estrutura bloco_consultas utilizando um laco for.",
	                    " Apos esse procedimento, corre os campos consulta via ponteiro mostrando valor total da consulta.");
	    int resposta, NRR, i;
	    HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
	    FILE *arquivo_binario_consulta = fopen("arquivo_binario_consultas.bin", "rb");
		struct bloco_consulta *p_bloco;
		p_bloco = (struct bloco_consulta *) malloc(sizeof(struct bloco_consulta));//aloca memoria para um bloco de consulta e coloca o endereco alocado em p_bloco         
	    //primeiro testa se o arquivo binario existe se nao pergunta se quer criar		
		if (!arquivo_binario_consulta)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		//Lendo primeiro campo de consulta medica no arquivo binario e atribuindo via ponteiro ao campo vetorConsultas da struct bloco_consulta
		for(NRR=1;NRR<12;NRR++){ // corre o nrr de 1 a 11
			fseek(arquivo_binario_consulta,((NRR-1)*sizeof(struct consulta)),SEEK_SET);//vai ate a posicao da consulta medica a ser lida
			fread((*p_bloco).vetorConsultas+(NRR-1),sizeof(struct consulta),1,arquivo_binario_consulta); //NRR-1 para colocar na posicao de memoria certa pois o NRR e a posicao do dado no arquivo q comeca em 1
		}
		strcpy((*p_bloco).titulo,"Bloco de consultas realizadas pela UNIMED MARINGA.");         
		printf("%s\n",(*p_bloco).titulo);
		func_gen_linhap();
		for(i=0;i<11;i++)
		{
			  printf("Numero da Consulta: %d\n", (*p_bloco).vetorConsultas[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", (*((*p_bloco).vetorConsultas+i)).nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", (*p_bloco).vetorConsultas[i].data_consulta.dia,(*p_bloco).vetorConsultas[i].data_consulta.mes,(*p_bloco).vetorConsultas[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", (*p_bloco).vetorConsultas[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", (*p_bloco).vetorConsultas[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.porte);
			  printf("Filme             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.filme);
			  func_gen_linhac();
			  printf("Valor Total: ");
			  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			  printf("R$%0.2f\n",(((*p_bloco).vetorConsultas[i].item_consulta.novo_valor)+((*p_bloco).vetorConsultas[i].item_consulta.valor_custo)));
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  func_gen_linhac();

		}
		printf("\n\n\n"); 
	    system("PAUSE");
	
}
void func_11_01_06_valor_com_desconto(){
		func_gen_titulo(" Menu Principal->ED-11->Calcular valor com desconto de consulta.",
	                    " Alocando um endereco de memoria para uma variavel do tipo bloco_consultas, ",
	                    " lendo consulta por consulta do arquivo binario com o comando fred e preenchendo", 31,
	                    " via ponteiro o campo vetorConsultas da estrutura bloco_consultas utilizando um laco for.",
	                    " Apos esse procedimento, corre os campos consulta via ponteiro mostrando valores total e com desconto.");
	    int resposta, NRR, i;
	    HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
	    FILE *arquivo_binario_consulta = fopen("arquivo_binario_consultas.bin", "rb");
		struct bloco_consulta *p_bloco;
		p_bloco = (struct bloco_consulta *) malloc(sizeof(struct bloco_consulta));//aloca memoria para um bloco de consulta e coloca o endereco alocado em p_bloco         
	    //primeiro testa se o arquivo binario existe se nao pergunta se quer criar		
		if (!arquivo_binario_consulta)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		//Lendo primeiro campo de consulta medica no arquivo binario e atribuindo via ponteiro ao campo vetorConsultas da struct bloco_consulta
		for(NRR=1;NRR<12;NRR++){ // corre o nrr de 1 a 11
			fseek(arquivo_binario_consulta,((NRR-1)*sizeof(struct consulta)),SEEK_SET);//vai ate a posicao da consulta medica a ser lida
			fread((*p_bloco).vetorConsultas+(NRR-1),sizeof(struct consulta),1,arquivo_binario_consulta); //NRR-1 para colocar na posicao de memoria certa pois o NRR e a posicao do dado no arquivo q comeca em 1
		}
		strcpy((*p_bloco).titulo,"Bloco de consultas realizadas pela UNIMED MARINGA.");         
		printf("%s\n",(*p_bloco).titulo);
		func_gen_linhap();
		for(i=0;i<11;i++)
		{
			  printf("Numero da Consulta: %d\n", (*((*p_bloco).vetorConsultas+i)).numero_consulta);
			  printf("Nome do Paciente  : %s\n", (*((*p_bloco).vetorConsultas+i)).nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", (*p_bloco).vetorConsultas[i].data_consulta.dia,(*p_bloco).vetorConsultas[i].data_consulta.mes,(*p_bloco).vetorConsultas[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", (*p_bloco).vetorConsultas[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", (*p_bloco).vetorConsultas[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.porte);
			  printf("Filme             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.filme);
			  func_gen_linhac();
			  printf("Valor Total       : ");
			  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			  printf("R$%0.2f\n",((*p_bloco).vetorConsultas[i].item_consulta.novo_valor+(*p_bloco).vetorConsultas[i].item_consulta.valor_custo));
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Valor com desconto: ");
			  SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			  printf("R$%0.2f\n",(((*p_bloco).vetorConsultas[i].item_consulta.novo_valor+(*p_bloco).vetorConsultas[i].item_consulta.valor_custo)-(*p_bloco).vetorConsultas[i].item_consulta.valor_auxiliar));
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  func_gen_linhac();

		}
		printf("\n\n\n"); 
	    system("PAUSE");
}
void func_11_01_07_posicoes_pares_impares(){
	   func_gen_titulo(" Menu Principal->ED-11->Exibir posicoes pares seguida das impares.",
	                    " Alocando um endereco de memoria para uma variavel do tipo bloco_consultas, ",
	                    " lendo consulta por consulta do arquivo binario com o comando fred e preenchendo", 31,
	                    " via ponteiro o campo vetorConsultas da estrutura bloco_consultas utilizando um laco for.",
	                    " E exibindo acessando os dados por ponteiro as posicoes pares seguidas das impares.");
	    int resposta, NRR, i;
	    HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
	    FILE *arquivo_binario_consulta = fopen("arquivo_binario_consultas.bin", "rb");
		struct bloco_consulta *p_bloco;
		p_bloco = (struct bloco_consulta *) malloc(sizeof(struct bloco_consulta));//aloca memoria para um bloco de consulta e coloca o endereco alocado em p_bloco         
	    //primeiro testa se o arquivo binario existe se nao pergunta se quer criar		
		if (!arquivo_binario_consulta)//SE NAO EXISTE, PERGUNTA SE QUER CRIAR
		{
		    printf("\t\n\nEste arquivo binario nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
		    func_gen_linhap();
		    printf(">");
		    scanf("%d", &resposta);
		    if (resposta==1)//se o usuario desejar criar, o programa chama a funcao referente a criacao do arquivo binario
		    {   
		        func_gen_limpa_tela();
		        func_10_01_01_escrever_arquivo_binario();
		        return;
		    } 
		}
		//Lendo primeiro campo de consulta medica no arquivo binario e atribuindo via ponteiro ao campo vetorConsultas da struct bloco_consulta
		for(NRR=1;NRR<12;NRR++){ // corre o nrr de 1 a 11
			fseek(arquivo_binario_consulta,((NRR-1)*sizeof(struct consulta)),SEEK_SET);//vai ate a posicao da consulta medica a ser lida
			fread((*p_bloco).vetorConsultas+(NRR-1),sizeof(struct consulta),1,arquivo_binario_consulta); //NRR-1 para colocar na posicao de memoria certa pois o NRR e a posicao do dado no arquivo q comeca em 1
		}
		
		strcpy((*p_bloco).titulo,"Bloco de consultas realizadas pela UNIMED MARINGA.");                
		printf("%s\n",(*p_bloco).titulo);
		func_gen_linhap();
		func_gen_linhac();
		printf("\tPosicoes Pares\n");
		func_gen_linhap();
		for(i=0;i<11;i+=2)
		{
				  printf("Posicao: %d\n",i);
				  printf("Numero da Consulta: %d\n", (*p_bloco).vetorConsultas[i].numero_consulta);
				  printf("Nome do Paciente  : %s\n", (*((*p_bloco).vetorConsultas+i)).nome_paciente);
				  printf("Data da Consulta  : %d/%d/%d\n", (*p_bloco).vetorConsultas[i].data_consulta.dia,(*p_bloco).vetorConsultas[i].data_consulta.mes,(*p_bloco).vetorConsultas[i].data_consulta.ano);
				  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
				  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
				  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				  printf("Codigo            : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.codigo);
				  printf("Descricao         : %s\n", (*p_bloco).vetorConsultas[i].item_consulta.descricao);
				  printf("Novo Valor        : R$%0.2f \n", (*p_bloco).vetorConsultas[i].item_consulta.novo_valor);
				  printf("Valor Custo       : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_custo);
				  printf("Valor Auxiliar    : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_auxiliar);
				  printf("Porte             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.porte);
				  printf("Filme             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.filme);
				  func_gen_linhac(); 
		}
		printf("\n\n\n"); 
		func_gen_linhap();
		func_gen_linhac();
		printf("\tPosicoes Impares\n");
		func_gen_linhap();
		for(i=1;i<11;i+=2)
		{
				  printf("Posicao: %d\n",i);
				  printf("Numero da Consulta: %d\n", (*p_bloco).vetorConsultas[i].numero_consulta);
				  printf("Nome do Paciente  : %s\n", (*((*p_bloco).vetorConsultas+i)).nome_paciente);
				  printf("Data da Consulta  : %d/%d/%d\n", (*p_bloco).vetorConsultas[i].data_consulta.dia,(*p_bloco).vetorConsultas[i].data_consulta.mes,(*p_bloco).vetorConsultas[i].data_consulta.ano);
				  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
				  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
				  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				  printf("Codigo            : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.codigo);
				  printf("Descricao         : %s\n", (*p_bloco).vetorConsultas[i].item_consulta.descricao);
				  printf("Novo Valor        : R$%0.2f \n", (*p_bloco).vetorConsultas[i].item_consulta.novo_valor);
				  printf("Valor Custo       : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_custo);
				  printf("Valor Auxiliar    : R$%0.2f\n", (*p_bloco).vetorConsultas[i].item_consulta.valor_auxiliar);
				  printf("Porte             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.porte);
				  printf("Filme             : %d\n", (*p_bloco).vetorConsultas[i].item_consulta.filme);
				  func_gen_linhac(); 
		}
		printf("\n\n\n");
		
	    system("PAUSE");
}
void func_11_01_08_TAD_11(){
	func_gen_titulo(" Menu Principal->ED-10->TAD-11",
                    " ",
                    "                                                    TAD-11", 31,
                    "                                            ESPECIFICACAO DO TAD-11",
                    " ");
		printf("\n\t A TAD-11 teve como objetivo fazer uma alocacao estatica de memoria e manipular os dedados nela contidos.\n");
		printf("\n Nessa Atividade, implementamos 6 funcoes como descrito abaixo:\n");
		printf("\t (1) - func_11_01_02_visualizar_bloco()\n");
		printf("\t (2) - func_11_01_03_zerar_vauxiliar()\n");
		printf("\t (3) - func_11_01_04_esconder_nome()\n");
		printf("\t (4) - func_11_01_05_valor_total()\n");
		printf("\t (5) - func_11_01_06_valor_com_desconto()\n");
		printf("\t (6) - func_11_01_07_posicoes_pares_impares()\n\n");
		printf("\t --------------------------------------------------------------------\n");
		printf("\t                       EXPLICACAO DAS FUNCOES\n");
		printf("\t --------------------------------------------------------------------\n\n");	
		printf("\t (1) - Essa funcao le os dados do arquivo binario, aloca um espaco na memoria do tamanho bloco_consulta, e utilizando o ponteiro com o endereco de memora que foi previmente alocado, exibe todas as informacoes ali contidas.\n");
		printf("\t (2) - Utilizando ponteiro, essa funcao zera todos os valores auxiliares das consultas\n");
		printf("\t (3) - Tambem utilizando ponteiro essa funcao escreve ****** no lugar do nome do paciente na memoria.\n");
		printf("\t (4) - Acessando os valores das consultas utilizando ponteiro, essa funcao calcula o valor total da consulta\n");
		printf("\t (5) - Como na funcao (4) essa funcao acessa os valores das consultas utilizando ponteiro, e calcula valor com desonto\n");
		printf("\t (6) - Percorre a memoria utilizando um ponteiro mostrando as posicoes pares do vetor de consultas e em seguida as posicoes impares.\n");
		printf("\t --------------------------------------------------------------------\n");
		printf("\t   EXPLICACAO DAS VARIAVEIS UTILIZADAS PARA A MANIPULACAO DOS DADOS\n");
		printf("\t --------------------------------------------------------------------\n\n");	
		printf("\n\t Estruturas e variaveis utilizadas nesta TAD.\n");
		printf("\t\nVariaveis:\n\n");
		printf("\t(1) struct consulta{ int numero_consulta;\n");
		printf("\t                     char nome_paciente[5000];\n");
		printf("\t                     struct data data_consulta;\n");
		printf("\t                     struct item item_consulta;}\n");
		printf("\t(2) struct bloco_consulta{\n");
		printf("\t                          char titulo[300];\n");
		printf("\t                          struct consulta vetorConsultas[11];\n");
		printf("\t                         };\n");
		printf("\t(3) struct bloco_consulta *p_bloco");
		printf("\n\n\n");
		printf("  -Explicacao Para Variavel (1)\n  -----------------------------\n  *Struct do tipo consulta, foi criada para arganizar os dados de uma consulta medica contida no arquivo binario, sao esses dados: numero da consulta, nome do paciente, data da consulta e o item, onde o item significa o procedimento realizado pelo paciente na consulta medica.\n\n");
		printf("  -Explicacao Para Variavel (2)\n  -----------------------------\n  *Struct do tipo bloco_consulta, Esta estrutura foi criada para armazenar o titulo do bloco de consulta e um vetor de 11 posicoes de consultas. \n\n");
		printf("  -Explicacao Para Variavel (3)\n  -----------------------------\n  *Ponteiro de struct bloco_consulta que foi utilizado para armazena um endereco de memoria alocado com o tamanho de uma struct bloco_consulta. Esse ponteiro fo utilizado nas funcoes para manipular e exibir os dados em tela. \n\n");
		
		system("PAUSE");
}
void func_12_01_01_ler_20_ocorrencias_xml(){
		func_gen_titulo(" Menu Principal->ED-12->Ler as 20 ocorrencias do arquivo XML e exibir em tela.",
	                    " ",
	                    "                                Visualizacao de todas as consultas medicas existentes", 31,
	                    "                                           no ED-12 a partir do arquivo XML",
	                    " ");
		struct consulta vet_consulta[20];               
	    int i;
		int resposta;
	    char texto[5001];//usado para auxiliar a leitura do XML
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//passa o  vetor de consulta por parametro para a funcao ler as consultas (vet_consulta, tamanho)  
		func_gen_ler_vetor_consultas_do_ED12(vet_consulta, 20);
		//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
		if(vet_consulta[1].numero_consulta==-1)
		{
			return;
		}  
		//Depois de ter lido todas as consultas no arquivo XML, o programa vai escrever em tela o vetor de consultas
		//escreve itens apos serem ordenados pelo seu Novo Valor          
		printf("Consultas realizadas em um consultorio medico do plano de saude Unimed Maringa.\n");
		func_gen_linhap();
		for(i=0;i<20;i++)
		{
			  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
			  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
			  func_gen_linhac(); 
		}
		printf("\n\n\n");
		system("PAUSE");
}
void func_12_01_02_gravar_primeiro_nodo(){
		func_gen_titulo(" Menu Principal->ED-12->Gravar o primeiro nodo na memoria.",
	                    " ",
	                    "                      Alocacao e gravacao do primeiro nodo da Lista de Struct Consulta", 31,
	                    "                      OBS: As informacoes adicionadas no primeiro nodo sao lidas do arquivo XML",
	                    "                      e estao contidas dentro da TAG ED-12.");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    //Se o ponteiro nao tiver nulo aloca o primeiro espaco de memoria e armazena as informacoes
		if(PE1==NULL){
			printf("\n\n\n\n");
			//Aloca memoria para o primeiro nodo e salva endereco no ponteirao inicial PE1
			PE1=(struct nodo_consulta*) malloc(sizeof(struct nodo_consulta));
			printf("\tPE1 recebeu o endereco de memoria imediatamente alocado do tamanho de struct nodo_consulta.\n\tEndereco: %d", PE1);
			struct consulta vet_consulta[1];
			struct nodo_consulta nodo;
			func_gen_ler_vetor_consultas_do_ED12(vet_consulta, 1);//lendo a primeira posicao no arquivo XML no ED12
			nodo.vConsulta=vet_consulta[0];
			func_gen_push_nodo(PE1, nodo);
			printf("\n\n\n\n");
			func_gen_linhac();
			printf("\tLendo o primeiro nodo que foi gravado na memoria utilizando o ponteiro PE1:\n");
			func_gen_linhac();
			SetConsoleTextAttribute(hConsole, 128);
			printf(" Nodo: 1 / Endereco deste nodo: %d\n",PE1);
			SetConsoleTextAttribute(hConsole, 240);
			printf("Numero da Consulta: %d\n", (*PE1).vConsulta.numero_consulta);
			printf("Nome do Paciente  : %s\n", (*PE1).vConsulta.nome_paciente);
			printf("Data da Consulta  : %d/%d/%d\n", (*PE1).vConsulta.data_consulta.dia,(*PE1).vConsulta.data_consulta.mes,(*PE1).vConsulta.data_consulta.ano);
			SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("Codigo            : %d\n", (*PE1).vConsulta.item_consulta.codigo);
			printf("Descricao         : %s\n", (*PE1).vConsulta.item_consulta.descricao);
			printf("Novo Valor        : R$%0.2f \n", (*PE1).vConsulta.item_consulta.novo_valor);
			printf("Valor Custo       : R$%0.2f\n", (*PE1).vConsulta.item_consulta.valor_custo);
			printf("Valor Auxiliar    : R$%0.2f\n", (*PE1).vConsulta.item_consulta.valor_auxiliar);
			printf("Porte             : %d\n", (*PE1).vConsulta.item_consulta.porte);
			printf("Filme             : %d\n", (*PE1).vConsulta.item_consulta.filme);
			printf("-------------------------\n");
			printf("   nodo.p: %d\n",(*PE1).p);
			printf("-------------------------\n");
			func_gen_linhac();
			func_gen_linhap(); 
			//Le as informacoes do arquivo xml
		}
		else
		{
			printf("\n\n\n\n");
			printf("\tO primeiro nodo ja existe, onde o ponteiro de entrada para ele e PE1=%d,\n\tva para a funcao (3) desta atividade e carregue os demais nodos.", PE1);
			printf("\n\n\n\n");
			func_gen_linhap();
			printf("\tLendo o primeiro nodo que foi gravado na memoria utilizando o ponteiro PE1:\n");
			func_gen_linhac();
			SetConsoleTextAttribute(hConsole, 128);
			printf(" Nodo: 1 / Endereco deste nodo: %d\n",PE1);
			SetConsoleTextAttribute(hConsole, 240);
			printf("Numero da Consulta: %d\n", (*PE1).vConsulta.numero_consulta);
			printf("Nome do Paciente  : %s\n", (*PE1).vConsulta.nome_paciente);
			printf("Data da Consulta  : %d/%d/%d\n", (*PE1).vConsulta.data_consulta.dia,(*PE1).vConsulta.data_consulta.mes,(*PE1).vConsulta.data_consulta.ano);
			SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("Codigo            : %d\n", (*PE1).vConsulta.item_consulta.codigo);
			printf("Descricao         : %s\n", (*PE1).vConsulta.item_consulta.descricao);
			printf("Novo Valor        : R$%0.2f \n", (*PE1).vConsulta.item_consulta.novo_valor);
			printf("Valor Custo       : R$%0.2f\n", (*PE1).vConsulta.item_consulta.valor_custo);
			printf("Valor Auxiliar    : R$%0.2f\n", (*PE1).vConsulta.item_consulta.valor_auxiliar);
			printf("Porte             : %d\n", (*PE1).vConsulta.item_consulta.porte);
			printf("Filme             : %d\n", (*PE1).vConsulta.item_consulta.filme);
			printf("-------------------------\n");
			printf("   nodo.p: %d\n",(*PE1).p);
			printf("-------------------------\n");
			func_gen_linhac();
			func_gen_linhap(); 
		}
		system("PAUSE");
}
void func_12_01_03_gravar_demais_nodos(){
		func_gen_titulo(" Menu Principal->ED-12->Gravar os demais nodos na memoria.",
	                    " ",
	                    "     Alocacao e gravacao dos demais nodos da Lista de Struct Consulta", 31,
	                    "     OBS: As informacoes adicionadas nos nodos sao lidas do arquivo XML",
	                    "     e estao contidas dentro da TAG ED-12.");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    if(PE1!=NULL){
	    	if((*PE1).p==NULL){// Testa se ainda nao foram adicionado os demais nodos na lista	
		    	int i;
		    	struct consulta vet_consulta[20];
				struct nodo_consulta nodo;
				struct nodo_consulta *p_nodo_aux;
				func_gen_ler_vetor_consultas_do_ED12(vet_consulta, 20);//lendo todas posicoes(consultas) no arquivo XML no ED12
				p_nodo_aux=(struct nodo_consulta*) malloc(sizeof(struct nodo_consulta));//entra no primeiro nodo e aloca memoria e atribui ao ponteiro do primeiro nodo
				(*PE1).p=p_nodo_aux;//guarda o endereco de memoria recentemente alocado
				for(i=1;i<20;i++){//nao comeca do 1 pois o primeiro nodo ja esta em memoria
					//o atribuo a struct consulta ao nodo
					nodo.vConsulta=vet_consulta[i];					
					if(i!=19){// se nao tiver no ultimo item adicionado vai alocando memoria para o proximo
							(*p_nodo_aux).p=(struct nodo_consulta*) malloc(sizeof(struct nodo_consulta));//aloca e atribui o endereco de memoria no novo nodo
					}
					func_gen_push_nodo(p_nodo_aux, nodo);//adiciona nodo na posicao de memoria apontada pelo p_nodo_aux. que no primeiro looping e o ponteiro do p primeiro nodo ja setado fora do for.
					p_nodo_aux=(*p_nodo_aux).p;//corre o ponteiro de leitura pra o proximo nodo
				}
				printf("\n\n\n\n");
				printf("\tOs 19 nodos restantes acabam de ser adicionados a lista.\n\tVa para a funcao (5) caso deseja exibilos em tela.", PE1);
				printf("\n\n\n\n");
				func_gen_linhap();
	    	}
	    	else
	    	{
	    		printf("\n\n\n\n");
				printf("\tA lista ja foi criada anteriormente com 20 nodos,\n\tVa para a funcao (5) caso deseja exibilos em tela.", PE1);
				printf("\n\n\n\n");
				func_gen_linhap();
			}
		}
		else{
	    	printf("\n\n\n\n");
			printf("\tO primeiro nodo ainda nao existe, va para a funcao (2)\n\te crie o primeiro nodo para entao adicionar os demais.", PE1);
			printf("\n\n\n\n");
			func_gen_linhap();
			}
	    system("PAUSE");
}
void func_12_01_04_limpar_memoria(){
		func_gen_titulo(" Menu Principal->ED-12->Limpar Memoria.",
	                    " ",
	                    "     Correndo todos os nodos liberando a memoria e anulando os ponteiros dos nodos.", 31,
	                    " ",
	                    " ");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    struct nodo_consulta *p_nodo_aux=PE1;
	    struct nodo_consulta *p_nodo_aux2;
	    int i=0;
	    printf("\n\n\n\n");	    
	    while(p_nodo_aux!=NULL){// enquanto nao chegar no ultimo nodo, vai escrevendo eles em tela.
	    	printf("\tLimpando nodo %2d e liberando endereco %d\n", i, p_nodo_aux);
	    	p_nodo_aux2=(*p_nodo_aux).p;
	    	p_nodo_aux=NULL;
	    	free(p_nodo_aux); //limpa o ponteiro p deste no
			p_nodo_aux=p_nodo_aux2;
			i++;
		}
		//limpa o ponteirao de entrada PE1;
		printf("\n\tLimpando PE1.\n");	
		PE1=NULL;
		free(PE1);
		PE1=NULL;
		printf("\n\n\n\n");
	    func_gen_linhap();
	    
	    system("PAUSE");	

}
void func_12_01_05_exibir_nodos(){
		func_gen_titulo(" Menu Principal->ED-12->Entrar na lista e exibir as informacoes de todos os nodos.",
	                    " ",
	                    "     Exibindo todos os nodos gravados na memoria, caso eles existam.", 31,
	                    "     No caso de existir somente o primeiro, apenas o primeiro sera exibido.",
	                    " ");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    struct nodo_consulta *p_nodo_aux=PE1;
	    int i=0;
	    while(p_nodo_aux!=NULL){// enquanto nao chegar no ultimo nodo, vai escrevendo eles em tela.
	    	
	    	SetConsoleTextAttribute(hConsole, 128);
			printf(" Nodo: %d / Endereco deste nodo: %d\n",i,p_nodo_aux);
			SetConsoleTextAttribute(hConsole, 240);
			printf("   -------------------------------------------------------------------\n");
			printf("   Struct nodo_consulta\n");
			printf("   -------------------------------------------------------------------\n");
			printf("   |        -----------------------------------------------------------\n");
			printf("   |        Struct Consulta\n");
			printf("   |        -----------------------------------------------------------\n");
			printf("   |        |  Numero da Consulta: %d\n", (*p_nodo_aux).vConsulta.numero_consulta);
			printf("   |        |  Nome do Paciente  : %s\n", (*p_nodo_aux).vConsulta.nome_paciente);
			printf("   |        |  Data da Consulta  : %d/%d/%d\n", (*p_nodo_aux).vConsulta.data_consulta.dia,(*p_nodo_aux).vConsulta.data_consulta.mes,(*p_nodo_aux).vConsulta.data_consulta.ano);
			printf("   |        |  ");
			SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
		                	printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("   |        |  Codigo            : %d\n", (*p_nodo_aux).vConsulta.item_consulta.codigo);
			printf("   |        |  Descricao         : %s\n", (*p_nodo_aux).vConsulta.item_consulta.descricao);
			printf("   |        |  Novo Valor        : R$%0.2f \n", (*p_nodo_aux).vConsulta.item_consulta.novo_valor);
			printf("   |        |  Valor Custo       : R$%0.2f\n", (*p_nodo_aux).vConsulta.item_consulta.valor_custo);
			printf("   |        |  Valor Auxiliar    : R$%0.2f\n", (*p_nodo_aux).vConsulta.item_consulta.valor_auxiliar);
			printf("   |        |  Porte             : %d\n", (*p_nodo_aux).vConsulta.item_consulta.porte);
			printf("   |        |  Filme             : %d\n", (*p_nodo_aux).vConsulta.item_consulta.filme);
			printf("   |        -----------------------------------------------------------\n");
			printf("   |        nodo.p: %d\n",(*p_nodo_aux).p);
			printf("   -------------------------------------------------------------------\n");
			func_gen_linhac(); 
			//vai para o proximo nodo
			p_nodo_aux=(*p_nodo_aux).p;
			i++;
		}
	    func_gen_linhap();
	    printf("\n\n\n\n");
	    system("PAUSE");	
}
void func_12_01_06_zerar_valor_auxiliar(){
	func_gen_titulo(" Menu Principal->ED-12->Zerar valor auxiliar de todos os nodos.",
	                    " ",
	                    "     Correndo todos os nodos e zerando valor auxiliar.", 31,
	                    " ",
	                    " ");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    struct nodo_consulta *p_nodo_aux=PE1;
	    struct nodo_consulta *p_nodo_aux2;
	    int i=0;
	    printf("\n\n\n\n");	    
	    while(p_nodo_aux!=NULL){// enquanto nao chegar no ultimo nodo, vai escrevendo eles em tela.
	    	p_nodo_aux2=(*p_nodo_aux).p;
	    	(*p_nodo_aux).vConsulta.item_consulta.valor_auxiliar=0.0;
			p_nodo_aux=p_nodo_aux2;
			i++;
		}
		//limpa o ponteirao de entrada PE1;
		printf("\tOs valores auxiliares de todos os nos foram zerados!");
		printf("\n\n\n\n");
	    func_gen_linhap();
	    system("PAUSE");	
}
void func_12_01_07_valor_total(){
		func_gen_titulo(" Menu Principal->ED-12->Calcular valor total de consulta.",
	                    " ",
	                    " Exibindo todos os nodos gravados na memoria, calculando o valor total da consulta.", 31,
	                    " ",
	                    " ");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    struct nodo_consulta *p_nodo_aux=PE1;
	    int i=0;
	    while(p_nodo_aux!=NULL){// enquanto nao chegar no ultimo nodo, vai escrevendo eles em tela.
	    	
	    	SetConsoleTextAttribute(hConsole, 128);
			printf(" Nodo: %d / Endereco deste nodo: %d\n",i,p_nodo_aux);
			SetConsoleTextAttribute(hConsole, 240);
			printf("   -------------------------------------------------------------------\n");
			printf("   Struct nodo_consulta\n");
			printf("   -------------------------------------------------------------------\n");
			printf("   |        -----------------------------------------------------------\n");
			printf("   |        Struct Consulta\n");
			printf("   |        -----------------------------------------------------------\n");
			printf("   |        |  Numero da Consulta: %d\n", (*p_nodo_aux).vConsulta.numero_consulta);
			printf("   |        |  Nome do Paciente  : %s\n", (*p_nodo_aux).vConsulta.nome_paciente);
			printf("   |        |  Data da Consulta  : %d/%d/%d\n", (*p_nodo_aux).vConsulta.data_consulta.dia,(*p_nodo_aux).vConsulta.data_consulta.mes,(*p_nodo_aux).vConsulta.data_consulta.ano);
			printf("   |        |  ");
			SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
		                	printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("   |        |  Codigo            : %d\n", (*p_nodo_aux).vConsulta.item_consulta.codigo);
			printf("   |        |  Descricao         : %s\n", (*p_nodo_aux).vConsulta.item_consulta.descricao);
			printf("   |        |  Novo Valor        : R$%0.2f \n", (*p_nodo_aux).vConsulta.item_consulta.novo_valor);
			printf("   |        |  Valor Custo       : R$%0.2f\n", (*p_nodo_aux).vConsulta.item_consulta.valor_custo);
			printf("   |        |  Valor Auxiliar    : R$%0.2f\n", (*p_nodo_aux).vConsulta.item_consulta.valor_auxiliar);
			printf("   |        |  Porte             : %d\n", (*p_nodo_aux).vConsulta.item_consulta.porte);
			printf("   |        |  Filme             : %d\n", (*p_nodo_aux).vConsulta.item_consulta.filme);
			printf("   |        -----------------------------------------------------------\n");
			printf("   |        nodo.p: %d\n",(*p_nodo_aux).p);
			printf("   -------------------------------------------------------------------\n");
			printf("Valor Total: ");
			SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			printf("R$%0.2f\n",(((*p_nodo_aux).vConsulta.item_consulta.novo_valor)+((*p_nodo_aux).vConsulta.item_consulta.valor_custo)));
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			func_gen_linhac();
			//vai para o proximo nodo
			p_nodo_aux=(*p_nodo_aux).p;
			i++;
		}
	    func_gen_linhap();
	    printf("\n\n\n\n");
	    system("PAUSE");	
	
}
void func_12_01_08_valor_desconto(){
		func_gen_titulo(" Menu Principal->ED-12->Calcular valor com desconto de consulta.",
	                    " ",
	                    " Exibindo todos os nodos gravados na memoria, calculando o valor total da consulta.", 31,
	                    " ",
	                    " ");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    struct nodo_consulta *p_nodo_aux=PE1;
	    int i=0;
	    while(p_nodo_aux!=NULL){// enquanto nao chegar no ultimo nodo, vai escrevendo eles em tela.
	    	
	    	SetConsoleTextAttribute(hConsole, 128);
			printf(" Nodo: %d / Endereco deste nodo: %d\n",i,p_nodo_aux);
			SetConsoleTextAttribute(hConsole, 240);
			printf("   -------------------------------------------------------------------\n");
			printf("   Struct nodo_consulta\n");
			printf("   -------------------------------------------------------------------\n");
			printf("   |        -----------------------------------------------------------\n");
			printf("   |        Struct Consulta\n");
			printf("   |        -----------------------------------------------------------\n");
			printf("   |        |  Numero da Consulta: %d\n", (*p_nodo_aux).vConsulta.numero_consulta);
			printf("   |        |  Nome do Paciente  : %s\n", (*p_nodo_aux).vConsulta.nome_paciente);
			printf("   |        |  Data da Consulta  : %d/%d/%d\n", (*p_nodo_aux).vConsulta.data_consulta.dia,(*p_nodo_aux).vConsulta.data_consulta.mes,(*p_nodo_aux).vConsulta.data_consulta.ano);
			printf("   |        |  ");
			SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
		                	printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("   |        |  Codigo            : %d\n", (*p_nodo_aux).vConsulta.item_consulta.codigo);
			printf("   |        |  Descricao         : %s\n", (*p_nodo_aux).vConsulta.item_consulta.descricao);
			printf("   |        |  Novo Valor        : R$%0.2f \n", (*p_nodo_aux).vConsulta.item_consulta.novo_valor);
			printf("   |        |  Valor Custo       : R$%0.2f\n", (*p_nodo_aux).vConsulta.item_consulta.valor_custo);
			printf("   |        |  Valor Auxiliar    : R$%0.2f\n", (*p_nodo_aux).vConsulta.item_consulta.valor_auxiliar);
			printf("   |        |  Porte             : %d\n", (*p_nodo_aux).vConsulta.item_consulta.porte);
			printf("   |        |  Filme             : %d\n", (*p_nodo_aux).vConsulta.item_consulta.filme);
			printf("   |        -----------------------------------------------------------\n");
			printf("   |        nodo.p: %d\n",(*p_nodo_aux).p);
			printf("   -------------------------------------------------------------------\n");
			printf("Valor Total       : ");
			SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			printf("R$%0.2f\n",(((*p_nodo_aux).vConsulta.item_consulta.novo_valor)+((*p_nodo_aux).vConsulta.item_consulta.valor_custo)));
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("Valor com desconto: ");
			SetConsoleTextAttribute(hConsole, 252);//faz letra vermelha
			printf("R$%0.2f\n",(((*p_nodo_aux).vConsulta.item_consulta.novo_valor+(*p_nodo_aux).vConsulta.item_consulta.valor_custo)-(*p_nodo_aux).vConsulta.item_consulta.valor_auxiliar));
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			func_gen_linhac();
			//vai para o proximo nodo
			p_nodo_aux=(*p_nodo_aux).p;
			i++;
		}
	    func_gen_linhap();
	    printf("\n\n\n\n");
	    system("PAUSE");	
	
}
void func_12_01_09_TAD_12(){
	func_gen_titulo(" Menu Principal->ED-10->TAD-12",
                    " ",
                    "                                                    TAD-12", 31,
                    "                                            ESPECIFICACAO DO TAD-12",
                    "                                          Alocacao Dinamica de Memoria");
		printf("\n\t A TAD-12 teve como objetivo fazer alocacao dinamica de memoria. Foram lidos dados do arquivo xml continos na TAG ED-12.\n");
		printf("\t Nessa Atividade, implementamos 9 funcoes como descrito abaixo:\n");
		printf("\t (1) - func_12_01_01_ler_20_ocorrencias_xml()\n");
		printf("\t (2) - func_12_01_02_gravar_primeiro_nodo()\n");
		printf("\t (3) - func_12_01_03_gravar_demais_nodos()\n");
		printf("\t (4) - func_12_01_04_limpar_memoria()\n");
		printf("\t (5) - func_12_01_05_exibir_nodos()\n");
		printf("\t (6) - func_12_01_06_zerar_valor_auxiliar()\n");
		printf("\t (7) - func_12_01_07_valor_total()\n");
		printf("\t (8) - func_12_01_08_valor_desconto()\n");
		printf("\t (9) - func_gen_push_nodo()\n\n");
		printf("\t --------------------------------------------------------------------\n");
		printf("\t                       EXPLICACAO DAS FUNCOES\n");
		printf("\t --------------------------------------------------------------------\n");	
		printf("\t (1) - Essa funcao le as 20 consultas medicas contidas na ED-12 no arquivo XML e as exibe em tela.\n");
		printf("\t (2) - Essa funcao pega somente o primeiro registro de consultas no ED-12 no arquivo xml, aloca memoria para PE1\t\t       (Ponteiro de entrada da lista) e adiciona as informacoes na memoria onde o PE1 aponra para.\n");
		printf("\t (3) - A funcao de leitura e gravacaos dos demais nodos(19 nodos) contdos no xml sao feitos por essa funcao. E c\t\t       laro, essa funcao vai alocando a memoria e adicionando as informacoes nos nodos.\n");
		printf("\t (4) - A funcao 4 tem como funcionalidade entrar na lista pelo ponteiro de entrada e vai setando os ponteiros in\t\t       ternos dos nodos como NULL e vai dando a funcao free nos endereco de memoria.\n");
		printf("\t (5) - Essa funcao tem como objetivo percorrer a lista e exibir todos os dados na tela.\n");
		printf("\t (6) - Essa funcao percorre a lista atribuindo o valor 0.0 aos campos de valor auxiliar contidos em cada nodo.\n");
		printf("\t (7) - Essa funcao percorre a lista mostrando o valor total da consulta em tela juntamente com os demais dados d\t\t       o nodo.\n");
		printf("\t (8) - Como a funcao anterior, essa funcao percorre a lista mostrando o valor total e com desconto da consulta.\n");
		printf("\t (9) - Essa funcao foi implementada para receber um ponteiro e uma variavel do tipo nodo e gravar os dados dessa \t       variavel nodo na memoria para onde o ponteiro passado aponta.\n\n");
		printf("\t --------------------------------------------------------------------\n");
		printf("\t   EXPLICACAO DAS VARIAVEIS UTILIZADAS PARA A MANIPULACAO DOS DADOS\n");
		printf("\t --------------------------------------------------------------------\n");	
		printf("\t Estruturas e variaveis utilizadas nesta TAD.\n");
		printf("\n\tVariaveis:\n\n");
		printf("\t(1) struct consulta{ int numero_consulta;\n");
		printf("\t                     char nome_paciente[5000];\n");
		printf("\t                     struct data data_consulta;\n");
		printf("\t                     struct item item_consulta;}\n");
		printf("\t(2) struct nodo_consulta{;\n");
		printf("\t                         struct consulta vConsulta;\n");
		printf("\t                         struct nodo_consulta *p;\n");
		printf("\t                        }\n");
		printf("\t(3) struct bloco_consulta *PE1");
		printf("\n\n\n");
		printf("  -Explicacao Para Variavel (1)\n  -----------------------------\n  *Struct criada para manipular os itens lidos do arquivo XML do tipo consulta. Essa struct contem como subcampos numero_consulta que e usado para aramazenar o numero da cosulta medica, nome_paciente que e do tipo char e e usado para armazenar o nome do paciente, data_consulta que e do tipo data e e utilzada para armazena a data em que a consulta foi realizada. Tambem o subcampo item_consulta que e do tipo item, onde sao armazenados os dados do procedimento realizado na consulta medica.\n\n");
		printf("  -Explicacao Para Variavel (2)\n  -----------------------------\n  *Essa struct tem como finalidade modelar um nodo da lista criada e manipulada nas funcoes. Ela tem um subcampo do tipo consulta e um subcampo ponteiro de nodo_consulta. O subcampo do tipo consulta chamado vConsulta serve para armazenar os dados da consulta medica que foi lido do arquivo XML. Ja o ponteiro do tipo nodo_consulta serve para armazenar o endereco de memoria onde esta registrado o proximo nodo da lista.\n\n");
		printf("  -Explicacao Para Variavel (3)\n  -----------------------------\n  *Esse ponteiro, chamado informalmente de \"Ponteirao\", aramazena o endereco de memoria do primeiro nodo da lista. Ele foi criado como uma variavel global de modo que ao navegar no programa, nao perdemos a localizacao de entrada na lista, tornando possivel a persistencia das informacoes apos alteracao, visualizacao e manipulaca de dados por varias funcoes dessa TAD-12.\n\n");
		system("PAUSE");
	
}
void func_13_01_01_ler_20_ocorrencias_xml(){
		func_gen_titulo(" Menu Principal->ED-13->Ler as 20 ocorrencias do arquivo XML e exibir em tela.",
	                    " ",
	                    "                                Visualizacao de todas as consultas medicas existentes", 31,
	                    "                                           no ED-12 a partir do arquivo XML",
	                    " OBS: Apesar de estar na ED-13, utilizamos os mesmos dados da ED-12.");
		struct consulta vet_consulta[20];               
	    int i;
		int resposta;
	    char texto[5001];//usado para auxiliar a leitura do XML
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		//passa o  vetor de consulta por parametro para a funcao ler as consultas (vet_consulta, tamanho)  
		func_gen_ler_vetor_consultas_do_ED12(vet_consulta, 20);
		//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
		if(vet_consulta[1].numero_consulta==-1)
		{
			return;
		}  
		//Depois de ter lido todas as consultas no arquivo XML, o programa vai escrever em tela o vetor de consultas
		//escreve itens apos serem ordenados pelo seu Novo Valor          
		printf("Consultas realizadas em um consultorio medico do plano de saude Unimed Maringa.\n");
		func_gen_linhap();
		for(i=0;i<20;i++)
		{
			  printf("Numero da Consulta: %d\n", vet_consulta[i].numero_consulta);
			  printf("Nome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
			  printf("Data da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
			  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			  printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			  printf("Codigo            : %d\n", vet_consulta[i].item_consulta.codigo);
			  printf("Descricao         : %s\n", vet_consulta[i].item_consulta.descricao);
			  printf("Novo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
			  printf("Valor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
			  printf("Valor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
			  printf("Porte             : %d\n", vet_consulta[i].item_consulta.porte);
			  printf("Filme             : %d\n", vet_consulta[i].item_consulta.filme);
			  func_gen_linhac(); 
		}
		printf("\n\n\n");
		system("PAUSE");
}
void func_13_01_02_criar_primeiro_nodo_duplo(){
	    func_gen_titulo(" Menu Principal->ED-13->Criar o primeiro nodo na memoria.",
	                    " ",
	                    "                      Alocacao e gravacao do primeiro nodo da Lista de Struct Consulta", 31,
	                    "                      OBS: As informacoes adicionadas no primeiro nodo sao lidas do arquivo XML",
	                    "                      e estao contidas dentro da TAG ED-12.");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    if(pT==NULL && pF==NULL){
			printf("\n\n\n\n");
			//Aloca memoria para o primeiro nodo e salva endereco no ponteirao inicial PE1
			pT=(struct nodo_duplo_consulta*) malloc(sizeof(struct nodo_duplo_consulta));
			pF=pT;//pois existe apenas um nodo
			printf("\tpF e pT receberam o mesmo endereco de memoria imediatamente alocado do tamanho de struct nodo_duplo_consulta.\n\tEndereco: %d", pT);
			struct consulta vet_consulta[1];
			struct nodo_duplo_consulta nodo_duplo;
			func_gen_ler_vetor_consultas_do_ED12(vet_consulta, 1);//lendo a primeira posicao no arquivo XML no ED12
			nodo_duplo.vConsulta=vet_consulta[0];
			nodo_duplo.T=NULL;
			nodo_duplo.F=NULL;
			func_gen_push_nodo_duplo(pT, nodo_duplo);
			printf("\n\n\n\n");
			func_gen_linhac();
			printf("\tLendo o primeiro nodo que foi gravado na memoria utilizando o ponteiro pT e pF que nesse momento apontam para o mesmo endereco:\n");
			func_gen_linhac();
			SetConsoleTextAttribute(hConsole, 128);
			printf(" Primeiro nodo / Endereco deste nodo: %d\n",pT);
			SetConsoleTextAttribute(hConsole, 240);
			printf("Numero da Consulta: %d\n", (*pT).vConsulta.numero_consulta);
			printf("Nome do Paciente  : %s\n", (*pT).vConsulta.nome_paciente);
			printf("Data da Consulta  : %d/%d/%d\n", (*pT).vConsulta.data_consulta.dia,(*pT).vConsulta.data_consulta.mes,(*pT).vConsulta.data_consulta.ano);
			SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
			printf("INFORMACOES DO PROCEDIMENTO REALIZADO:\n");
			SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
			printf("Codigo            : %d\n", (*pT).vConsulta.item_consulta.codigo);
			printf("Descricao         : %s\n", (*pT).vConsulta.item_consulta.descricao);
			printf("Novo Valor        : R$%0.2f \n", (*pT).vConsulta.item_consulta.novo_valor);
			printf("Valor Custo       : R$%0.2f\n", (*pT).vConsulta.item_consulta.valor_custo);
			printf("Valor Auxiliar    : R$%0.2f\n", (*pT).vConsulta.item_consulta.valor_auxiliar);
			printf("Porte             : %d\n", (*pT).vConsulta.item_consulta.porte);
			printf("Filme             : %d\n", (*pT).vConsulta.item_consulta.filme);
			printf("-------------------------\n");
			printf("        PONTEIROS:\n");
			printf("nodo.T: %d\n",(*pT).T);
			printf("nodo.F: %d\n",(*pF).F);
			printf("-------------------------\n");
			func_gen_linhac();
			func_gen_linhap(); 
			//Le as informacoes do arquivo xml
		}
		else
		{
			printf("\n\n\n\n");
			printf("\tJa existe um ou mais nodos na lista.\n\tOs ponteiros de entrada para a lista sao:\n\n\tPela frente - pF=%d\n\tPor tras    - pT=%d", pF, pT);
			printf("\n\n\n\n");
			func_gen_linhap(); 
			//Le as informacoes do arquivo xml
		}
		system("PAUSE");
	    
	
}
void func_13_01_03_gravar_nodo_duplo_pf(){
	    func_gen_titulo(" Menu Principal->ED-13->Gravar mais um nodo na memoria pela frente(pF).",
	                    " ",
	                    "                                 Alocacao e gravacao de um nodo na frente da lista", 31,
	                    " OBS: As informacoes adicionadas nos nodos sao lidas do arquivo XML",
	                    " e estao contidas dentro da TAG ED-12.");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    if(pF!=NULL && pT!=NULL){
	    	int resposta;
	    	int i;
	    	struct consulta vet_consulta[20];
			struct nodo_duplo_consulta nodo_duplo;
			struct nodo_duplo_consulta *pF_nodo_duplo_aux;//o pT_nodo fica nulo
			pF_nodo_duplo_aux=(struct nodo_duplo_consulta*) malloc(sizeof(struct nodo_duplo_consulta));//entra no primeiro nodo e aloca memoria e atribui ao ponteiro do primeiro nodo
			(*pF).F=pF_nodo_duplo_aux;//guarda o endereco de memoria recentemente alocado
			func_gen_ler_vetor_consultas_do_ED12(vet_consulta, 20);//lendo todas posicoes(consultas) no arquivo XML no ED12
			//testa se a leitura foi feita corretamente, caso nao foi feita finaliza o procedimento
			if(vet_consulta[1].numero_consulta==-1)
			{
				return;
			}  
			
			//Depois de ter lido todas as consultas no arquivo XML, o programa vai escrever em tela o vetor de consultas
			//pede ao usuario para escolher a consulta que vai colocar no nodo da frente
			//escreve itens apos serem ordenados pelo seu Novo Valor          
			printf("Consultas realizadas em um consultorio medico do plano de saude Unimed Maringa.\n");
			func_gen_linhap();
			for(i=0;i<20;i++)
			{     
			      SetConsoleTextAttribute(hConsole, 112);//escreve linha com letra cinza
			      printf(" POSICAO: %d ",i);
			      SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				  printf("\tNumero da Consulta: %d\n", vet_consulta[i].numero_consulta);
				  printf("\tNome do Paciente  : %s\n", vet_consulta[i].nome_paciente);
				  printf("\tData da Consulta  : %d/%d/%d\n", vet_consulta[i].data_consulta.dia,vet_consulta[i].data_consulta.mes,vet_consulta[i].data_consulta.ano);
				  SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
				  printf("\tINFORMACOES DO PROCEDIMENTO REALIZADO:\n");
				  SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				  printf("\tCodigo            : %d\n", vet_consulta[i].item_consulta.codigo);
				  printf("\tDescricao         : %s\n", vet_consulta[i].item_consulta.descricao);
				  printf("\tNovo Valor        : R$%0.2f \n", vet_consulta[i].item_consulta.novo_valor);
				  printf("\tValor Custo       : R$%0.2f\n", vet_consulta[i].item_consulta.valor_custo);
				  printf("\tValor Auxiliar    : R$%0.2f\n", vet_consulta[i].item_consulta.valor_auxiliar);
				  printf("\tPorte             : %d\n", vet_consulta[i].item_consulta.porte);
				  printf("\tFilme             : %d\n", vet_consulta[i].item_consulta.filme);
				  func_gen_linhac(); 
			}
			func_gen_linhap();
			printf("\n\n\n");
			do{
				printf("\tInforme a posicao da consulta no vetor exibido para ser adicionado a frente da lista.");
				scanf("%d",&resposta);
			}while(resposta<0 || resposta>19);
			//depois de ter recebido a posicao da consulta, faz o push na lista
	    	nodo_duplo.vConsulta=vet_consulta[resposta];
	    	nodo_duplo.T=pF;
	    	//Exibindo nodo gravado		
	    	func_gen_push_nodo_duplo(pF_nodo_duplo_aux, nodo_duplo);
	    	
	    	
	     	printf("\n\n\n NODO LIDO DE antes de mudar pF Depois de Gravado:\n\n");
	     	printf("pT=%d\n",pT);
	     	printf("pF=%d (Atual)\n",pF);
	    	SetConsoleTextAttribute(hConsole, 112);//escreve linha com letra cinza

				SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				printf("\tNumero da Consulta: %d\n", (*pF).vConsulta.numero_consulta);
				printf("\tNome do Paciente  : %s\n", (*pF).vConsulta.nome_paciente);
				printf("\tData da Consulta  : %d/%d/%d\n", (*pF).vConsulta.data_consulta.dia,(*pF).vConsulta.data_consulta.mes,(*pF).vConsulta.data_consulta.ano);
				SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
				printf("\tINFORMACOES DO PROCEDIMENTO REALIZADO:\n");
				SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				printf("\tCodigo            : %d\n", (*pF).vConsulta.item_consulta.codigo);
				printf("\tDescricao         : %s\n", (*pF).vConsulta.item_consulta.descricao);
				printf("\tNovo Valor        : R$%0.2f \n", (*pF).vConsulta.item_consulta.novo_valor);
				printf("\tValor Custo       : R$%0.2f\n", (*pF).vConsulta.item_consulta.valor_custo);
				printf("\tValor Auxiliar    : R$%0.2f\n", (*pF).vConsulta.item_consulta.valor_auxiliar);
				printf("\tPorte             : %d\n", (*pF).vConsulta.item_consulta.porte);
				printf("\tFilme             : %d\n", (*pF).vConsulta.item_consulta.filme);
				printf("-------------------------\n");
				printf("        PONTEIROS:\n");
				printf("nodo.T: %d\n",(*pF).T);
				printf("nodo.F: %d\n",(*pF).F);
				printf("-------------------------\n");
				func_gen_linhac();
				
				pF=pF_nodo_duplo_aux;//o pF recebe o endereco do novo no da frente
				
	     	    printf("\n\n\n NODO LIDO DE depois de mudar pF Depois de Gravado:\n\n",pF);
	     	    printf("pT=%d\n",pT);
	     	    printf("pF=%d (Atual)\n",pF);
				SetConsoleTextAttribute(hConsole, 112);//escreve linha com letra cinza
				SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				printf("\tNumero da Consulta: %d\n", (*pF).vConsulta.numero_consulta);
				printf("\tNome do Paciente  : %s\n", (*pF).vConsulta.nome_paciente);
				printf("\tData da Consulta  : %d/%d/%d\n", (*pF).vConsulta.data_consulta.dia,(*pF).vConsulta.data_consulta.mes,(*pF).vConsulta.data_consulta.ano);
				SetConsoleTextAttribute(hConsole, 247);//escreve linha com letra cinza
				printf("\tINFORMACOES DO PROCEDIMENTO REALIZADO:\n");
				SetConsoleTextAttribute(hConsole, 240);//retorna ao padrao de cor normal
				printf("\tCodigo            : %d\n", (*pF).vConsulta.item_consulta.codigo);
				printf("\tDescricao         : %s\n", (*pF).vConsulta.item_consulta.descricao);
				printf("\tNovo Valor        : R$%0.2f \n", (*pF).vConsulta.item_consulta.novo_valor);
				printf("\tValor Custo       : R$%0.2f\n", (*pF).vConsulta.item_consulta.valor_custo);
				printf("\tValor Auxiliar    : R$%0.2f\n", (*pF).vConsulta.item_consulta.valor_auxiliar);
				printf("\tPorte             : %d\n", (*pF).vConsulta.item_consulta.porte);
				printf("\tFilme             : %d\n", (*pF).vConsulta.item_consulta.filme);
				printf("-------------------------\n");
				printf("        PONTEIROS:\n");
				printf("nodo.T: %d\n",(*pF).T);
				printf("nodo.F: %d\n",(*pF).F);
				printf("-------------------------\n");
				func_gen_linhac();
	    }
	    else
	    {
	    	printf("\n\n\n\tO primeiro nodo ainda nao existe, va para a funcao (2)\n\te crie o primeiro nodo para entao adicionar os demais.\n\n\n");
	    	func_gen_linhap();
		}
		
		system("PAUSE");
	
}
void func_13_01_04_gravar_nodo_duplo_pt(){
	
}
void func_13_01_05_exibir_nodos_duplo_pf(){
	    func_gen_titulo(" Menu Principal->ED-13->Entrar na lista e exibir as informacoes de todos os nodos pela frente(pF).",
	                    " ",
	                    "                            Exibindo a lista entrando pelo ponteiro da frente pF", 31,
	                    " OBS: Os dados exibidos estao gravados na memoria RAM.",
	                    " ");
	    HANDLE hConsole;
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    printf("esta sendo passado pF=%d\n\n",pF);
	    func_gen_exibir_lista_pF(pF);
	    func_gen_linhac();
		system("PAUSE");
}
void func_13_01_06_exibir_nodos_duplo_pt(){
}
void func_13_01_07_TAD_13(){
}
/*
================================================================================
                          FUNÇÕES DE SEGUNDO NIVEL DE MENU
================================================================================
*/
int func_03_01_sub_menu()
{    
     int resposta;
     printf("\n\n\n\t(1)Criar Arquivo XML.\n");
     printf("\t(2)Ler Tabela TUSS do XML.\n");
     printf("\t(3)Escrever Arquivo Binario a Partir do arquivo XML.\n");
     printf("\t(4)TAD-03.\n\n");
     printf("\t(0)Voltar.\n\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 1:
            func_gen_limpa_tela();
            func_03_01_01_escrever_arquivo_xml();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_03_01_02_ler_tabela_tuss_xml();
        	return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_03_01_03_escrever_arquivo_binario();
            return 0;
       break;
       case 4:
            func_gen_limpa_tela();
            func_03_01_04_TAD();
            return 0;
       break;
	   case 0:
			return 1;
	   break;
	   default:
			return 1;
	   break;
     }     
}
int func_04_01_sub_menu()
{
     int resposta;
     printf("\n\n\n\n\t(1)Visualizar Arquivo Binario.\n");
     printf("\t(2)Ler Item Especifico.\n");
     printf("\t(3)TAD-04.\n\n");
     printf("\t(0)Voltar.\n\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 1:
            func_gen_limpa_tela();
            func_04_01_01_visualizar_arquivo_binario();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_04_01_02_ler_item_especifico();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_04_01_03_TAD();
            return 0;
       break;
       case 0:
            return 1;
       break;
       default:
       	    return 1;
       break;
     }     
}
int func_05_01_sub_menu()
{
     int resposta;
     printf("\n\n\n\n\t(1)Carregar Codigos\n");
     printf("\t(2)Carregar Descricoes.\n");
     printf("\t(3)Carregar Valores.\n");
     printf("\t(4)Carregar Matrizes de Valores.\n");
     printf("\t(5)Somar Colunas da Matriz.\n");
     printf("\t(6)TAD-05\n\n");
     printf("\t(0)voltar\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 1:
            func_gen_limpa_tela();
            func_05_01_01_carregar_codigos();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_05_01_02_carregar_descricoes();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_05_01_03_carregar_valores();
            return 0;
       break;
       case 4:
            func_gen_limpa_tela();
            func_05_01_04_carregar_matrizes();
            return 0;
       break;
       case 5:
            func_gen_limpa_tela();
            func_05_01_05_somar_colunas();
            return 0;
       break;
        case 6:
            func_gen_limpa_tela();
            func_05_01_06_TAD_05();
            return 0;
       break;
       case 0:
       		return 1;
       break;
       default:
       	    return 1;
       break;
     }     
}
int func_06_01_sub_menu()
{
	int resposta;
     printf("\n\n\n\n\t(1)Ordenar Vetor de itens por ordem crescente de Novos Valores utilizando BubbleSort.\n");
     printf("\t(2)Fazer Pesquisa Binaria No Vetor de Itens Por Codigo\n");
     printf("\t(3)Fazer Pesquisa Binaria No Vetor de Itens Por Codigo(Com DEBUG)\n");
     printf("\t(4)TAD-06\n\n");
     printf("\t(0)Voltar\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 0:
            return 1;
	   break;
       case 1:
            func_gen_limpa_tela();
            func_06_01_01_ordenacao_bubblesort();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_06_01_02_pesquisa_binaria();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_06_01_03_pesquisa_binaria_debug();
            return 0;
       break;
       case 4:
            func_gen_limpa_tela();
            func_06_01_04_TAD_06();
            return 0;
       break;
       default:
       	    return 1;
       break;
     }     
}
int func_07_01_sub_menu()
{
	int resposta;
     printf("\n\n\n\n\t(1)Visualizar todas as consultas.\n");
     printf("\t(2)Calcular valor total de uma consulta.\n");
     printf("\t(3)Calcular valor com desconto de uma consulta.\n");
     printf("\t(4)TAD-07\n\n");
     printf("\t(0)Voltar\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 0:
            return 1;
	   break;
       case 1:
            func_gen_limpa_tela();
            func_07_01_01_ver_consultas();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_07_01_02_calcular_valor_total_consulta();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_07_01_03_calcular_valor_desconto_consulta();
            return 0;
       break;
       case 4:
            func_gen_limpa_tela();
            func_07_01_04_TAD_07();
            return 0;
       break;
       default:
       	    return 1;
       break;
     }     
}
int func_08_01_sub_menu()
{
	int resposta;
     printf("\n\n\n\n\t(1)Escolher consulta por numero.\n");
     printf("\t(2)Sortear uma consulta.\n");
     printf("\t(3)TAD-08\n\n");
     printf("\t(0)Voltar\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 0:
            return 1;
	   break;
       case 1:
            func_gen_limpa_tela();
            func_08_01_01_ecolher_consulta();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_08_01_02_sortear_consulta();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_08_01_03_TAD_08();
            return 0;
       break;
       default:
       	    return 1;
       break;
     }     
}
int func_09_01_sub_menu()
{
	int resposta;
     printf("\n\n\n\n\t(1)Escrever arquivo sequencial textual.\n");
     printf("\t(2)Ler arquivo sequencial textual.\n");
     printf("\t(3)Calcular valor total da consulta.\n");
     printf("\t(4)Calcular valor com desconto da consulta.\n");
     printf("\t(5)TAD-09\n\n");
     printf("\t(0)Voltar\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 0:
            return 1;
	   break;
       case 1:
            func_gen_limpa_tela();
            func_09_01_01_escrever_arquivo_textual();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_09_01_02_ler_arquivo_textual();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_09_01_03_calcular_valor_total();
            return 0;
       break;
       case 4:
            func_gen_limpa_tela();
            func_09_01_04_calcular_valor_com_desconto();
            return 0;
       break;
       case 5:
            func_gen_limpa_tela();
            func_09_01_05_TAD_09();
            return 0;
       break;
       default:
       	    return 1;
       break;
     }     
}
int func_10_01_sub_menu()
{
	int resposta;
     printf("\n\n\n\n\t(1)Escrever arquivo binario.\n");
     printf("\t(2)Visualizar todo arquivo binario.\n");
     printf("\t(3)Visualizar todo o indice.\n");
     printf("\t(4)Consultar arquivo binario utilizando o indice\n");
     printf("\t(5)Calcular valor total de consulta\n");
     printf("\t(6)Calcular valor com desconto de consulta\n");
     printf("\t(7)TAD-10\n\n");
     printf("\t(0)Voltar\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 0:
            return 1;
	   break;
       case 1:
            func_gen_limpa_tela();
            func_10_01_01_escrever_arquivo_binario();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_10_01_02_ler_arquivo_binario();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_10_01_03_ler_indice();
            return 0;
       break;
       case 4:
            func_gen_limpa_tela();
            func_10_01_04_consultar_usando_indice();
            return 0;
       break;
       case 5:
            func_gen_limpa_tela();
            func_10_01_05_valor_total();
            return 0;
       break;
       case 6:
            func_gen_limpa_tela();
            func_10_01_06_valor_com_desconto();
            return 0;
       break;
       case 7:
            func_gen_limpa_tela();
            func_10_01_07_TAD_10();
            return 0;
       break;
       default:
       	    return 1;
       break;
     }     
}
int func_11_01_sub_menu()
{
	int resposta;
     printf("\n\n\n\n\t(1)Escrever arquivo binario.\n");
     printf("\t(2)Visualizar todo o bloco de consultas.\n");
     printf("\t(3)Zerar valor auxiliar das consultas.\n");
     printf("\t(4)Esconder nome do paciente das consultas.\n");
     printf("\t(5)Calcular valor total de consulta.\n");
     printf("\t(6)Calcular valor com desconto de consulta.\n");
     printf("\t(7)Exibir posicoes pares seguida das impares.\n");
     printf("\t(8)TAD-11\n\n");
     printf("\t(0)Voltar\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 0:
            return 1;
	   break;
       case 1:
            func_gen_limpa_tela();
            func_10_01_01_escrever_arquivo_binario();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_11_01_02_visualizar_bloco();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_11_01_03_zerar_vauxiliar();
            return 0;
       break;
       case 4:
            func_gen_limpa_tela();
            func_11_01_04_esconder_nome();
            return 0;
       break;
       case 5:
            func_gen_limpa_tela();
            func_11_01_05_valor_total();
            return 0;
       break;
       case 6:
            func_gen_limpa_tela();
            func_11_01_06_valor_com_desconto();
            return 0;
       break;
       case 7:
            func_gen_limpa_tela();
            func_11_01_07_posicoes_pares_impares();
            return 0;
       break;
       case 8:
            func_gen_limpa_tela();
            func_11_01_08_TAD_11();
            return 0;
       break;
       default:
       	    return 1;
       break;
     }     
}
int func_12_01_sub_menu()
{
	int resposta;
     printf("\n\n\n\n\t(1)Ler as 20 ocorrencias do arquivo XML e exibir em tela.\n");
     printf("\t(2)Gravar o primeiro nodo na memoria.\n");
     printf("\t(3)Gravar os demais nodos na memoria.\n");
     printf("\t(4)Limpar Memoria.\n");
     printf("\t(5)Entrar na lista e exibir as informacoes de todos os nodos.\n");
     printf("\t(6)Zerar valor auxiliar de todos os nodos.\n");
     printf("\t(7)Calcular valor total das consultas.\n");
     printf("\t(8)Calcular valor com desconto das consultas.\n");
     printf("\t(9)TAD-12\n\n");
     printf("\t(0)Voltar\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 0:
            return 1;
	   break;
       case 1:
            func_gen_limpa_tela();
            func_12_01_01_ler_20_ocorrencias_xml();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_12_01_02_gravar_primeiro_nodo();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_12_01_03_gravar_demais_nodos();
            return 0;
       break;
       case 4:
            func_gen_limpa_tela();
            func_12_01_04_limpar_memoria();
            return 0;
       break;
       case 5:
            func_gen_limpa_tela();
            func_12_01_05_exibir_nodos();
            return 0;
       break;
       case 6:
            func_gen_limpa_tela();
            func_12_01_06_zerar_valor_auxiliar();
            return 0;
       break;
       case 7:
            func_gen_limpa_tela();
            func_12_01_07_valor_total();
            return 0;
       break;
       case 8:
            func_gen_limpa_tela();
            func_12_01_08_valor_desconto();
            return 0;
       break;
       case 9:
            func_gen_limpa_tela();
            func_12_01_09_TAD_12();
            return 0;
       break;
       default:
       	    return 1;
       break;
     }     
}
int func_13_01_sub_menu()
{
	int resposta;
     printf("\n\n\n\n\t(1)Ler as 20 ocorrencias do arquivo XML e exibir em tela.\n");
     printf("\t(2)Criar o primeiro nodo na memoria.\n");
     printf("\t(3)Gravar mais um nodo na memoria pela frente(pF).\n");
     printf("\t(4)Gravar mais um nodo na memoria por tras(pT).\n");
     printf("\t(5)Entrar na lista e exibir as informacoes de todos os nodos pela frente(pF).\n");
     printf("\t(6)Entrar na lista e exibir as informacoes de todos os nodos por tras(pT).\n");
     printf("\t(7)TAD-13\n\n");
     printf("\t(0)Voltar\n\n\n");
     func_gen_linhap();
     printf(">");
     scanf("%d", &resposta);
     switch (resposta)
     {
       case 0:
            return 1;
	   break;
       case 1:
            func_gen_limpa_tela();
            func_13_01_01_ler_20_ocorrencias_xml();
            return 0;
       break;
       case 2:
            func_gen_limpa_tela();
            func_13_01_02_criar_primeiro_nodo_duplo();
            return 0;
       break;
       case 3:
            func_gen_limpa_tela();
            func_13_01_03_gravar_nodo_duplo_pf();
            return 0;
       break;
       case 4:
            func_gen_limpa_tela();
            func_13_01_04_gravar_nodo_duplo_pt();
            return 0;
       break;
       case 5:
            func_gen_limpa_tela();
            func_13_01_05_exibir_nodos_duplo_pf();
            return 0;
       break;
       case 6:
            func_gen_limpa_tela();
            func_13_01_06_exibir_nodos_duplo_pt();
            return 0;
       break;
       case 7:
            func_gen_limpa_tela();
            func_13_01_07_TAD_13();
            return 0;
       break;
       default:
       	    return 1;
       break;
     }     
}
/*
================================================================================
                          FUNÇÕES DE PRIMEIRO NIVEL DE MENU
================================================================================
*/
void func_01_tema()
{
         func_gen_titulo(" ",
                         " ",
                         "                                          Tema: CONSULTORIO MEDICO", 31,
                         " ",
                         " ");
          char linha1[110], linha2[110], linha3[110], linha4[110], linha5[110]; 
          int i;
          int resposta;
          int posicao_leitura;
          int posicao_pos_leitura;
          char texto[5001];
          posicao_leitura=71;
          posicao_pos_leitura=0;
          FILE *arquivo = fopen("CONSULTORIO_MEDICO.xml", "r");
          //TESTA SE O ARQUIVO EXISTE
          if (!arquivo)//SE NAO, PERGUNTA SE QUER CRIAR
          {
                printf("\t\n\nEste arquivo nao esxiste, deseja cria-lo?(1-Sim/0-Nao)\n\n\n");
                func_gen_linhap();
                printf(">");
                scanf("%d", &resposta);
                if (resposta==1)
                {
                    func_gen_limpa_tela();            
                    func_03_01_01_escrever_arquivo_xml();
                    return;
                }
                else//SE SIM SAI DA FUNCAO
                {
                    return;
                }    
          }
          fclose (arquivo);
          for (i=0;i<8;i++)//Pula 22 linhas ate começar ler os dados da tabela
          { //a tag pula_linha nao existe, entao ele conta qts bytes tem cada linha e vai somando
              func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
              posicao_leitura = posicao_leitura + posicao_pos_leitura;   
          }
          //le linha 1
          func_gen_ler_tag("<linha1>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          strcpy(linha1,texto);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;  
          //le linha 2      
          func_gen_ler_tag("<linha2>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          strcpy(linha2,texto);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;  
          //le linha 3      
          func_gen_ler_tag("<linha3>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          strcpy(linha3,texto);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;  
          //le linha 4
          func_gen_ler_tag("<linha4>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          strcpy(linha4,texto);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;  
          //le linha 5
          func_gen_ler_tag("<linha5>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          strcpy(linha5,texto);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          func_gen_ler_tag("<pula_linha>", "CONSULTORIO_MEDICO.xml", texto, posicao_leitura, &posicao_pos_leitura);
          posicao_leitura = posicao_leitura + posicao_pos_leitura;
          //Escreve quadrado simples com as linhas lidas do XML   
          func_gen_quadrado_simples(linha1,
                                    linha2,
                                    linha3,
                                    linha4,
                                    linha5,6);
         func_gen_linhap();
}
void func_02_funcao()
{
         //Escreve Topo
         func_gen_titulo("                                 Padrao das Funcoes Para Consultorio Medico",
                         "                                 ==========================================",
                         "                                 Esta descrito nesta tela o padrao que sera", 31,
                         "                                 usado para as funcoes no desenvolvimento  ",
                         "                                 deste programa");
         //Escreve especificacoes das funcoes dentro de de borda caixas simples
         func_gen_quadrado_simples(" DEFINICAO DE UMA FUNCAO DENTRO DO PROGRAMA:",
                                   " Toda funcao comecara com a palavra func e logo depois um '_'",
                                   " e entao sera apresentado demais parametros como nivel de menu e nome da funcao.",
                                   " Exemplo:",
                                   " func_01_tema()",1);
         func_gen_quadrado_simples(" FUNCAO DE PRIMEIRO NIVEL:",
                                   " a funcao de primeiro nivel comecara com a palavra func seguida de '_' e logo apos",
                                   " o seu numero do seu respectivo nivel e so entao o seu nome depois de outro '_'.",
                                   " Exemplo:",
                                   " func_02_nome_da_funcao()",1);
         func_gen_quadrado_simples(" FUNCAO DE SEGUNDO NIVEL:",
                                   " Assim como a funcao de primeiro nivel, a funcao de segundo nivel vai seguir o padrao de comecar com func",
                                   " seguido do numero do Numero do TAD representando o primeiro nivel de menu e logo apos, um segundo numero",
                                   " representando a ordem dela no segundo nivel de menu. EXEMPLO:",
                                   " func_01_01_nome_da_funcao()",1);
         func_gen_quadrado_simples(" FUNCAO DE MAIS DE DOIS NIVEIS:",
                                   " A funcao que estive em mais de dois niveis, continuara seguindo o padrao de possuir um numero correspondente",
                                   " ao seu respectivo nivel. Vamos supor aqui uma funcao de nivel 03 de menu referente a uma lista por exemplo.",
                                   " func_03_01_01_ordenacao_de_lista()",
                                   " podemos observar a correspondencia dos 3 niveis mais o nome da funcao, e assim sera feito com niveis maiores.",1);
         func_gen_quadrado_simples(" FUNCOES GENERICAS:",
                                   " Chamaremos de funcoes genericas as funcoes que forem chamadas em mais de um lugar no programa.",
                                   " toda ela devera conter no lugar do primeiro nivel o sufixo '_gen_'. EXEMPLO:",
                                   " func_gen_limpa_tela()",
                                   " func_gen_linha()",1);
         func_gen_linhap();               
}        
void func_03_arquivo_xml()
{
	     int resp;
         do{
         	         func_gen_limpa_tela();
			         func_gen_titulo("Menu Principal->ED-03                   Manipulacao de arquivo XML",
			                         "                                                  ED -03",
			                         " ", 30,
			                         "                              Manipulacao da tabela TUSS da UNIMED DE MARINGA.",
			                         " ");
			         //chama o submenu da atividade 04
			         resp=func_03_01_sub_menu();
        }while(resp==0);
}
void func_04_arquivo()
{ 
         int resp;
         do{
			         func_gen_limpa_tela();
			         func_gen_titulo("Menu Principal->ED-04                 Manipulacao de arquivo BINARIO",
			                         "                                                  ED -04",
			                         " ", 30,
			                         "                              Manipulacao da tabela TUSS da UNIMED DE MARINGA.",
			                         " ");
			         resp=func_04_01_sub_menu();
	        }while(resp==0);
}

void func_05_vetor_matriz()
{
	    int resp;
        do{
        			 func_gen_limpa_tela();
			         func_gen_titulo("Menu Principal->ED-05                Manipulacao de Vetores e Matrizes",
			                         "                                                  ED -05",
			                         " ", 30,
			                         " ",
			                         " ");
			        resp=func_05_01_sub_menu();
        }while(resp==0);
     
}
void func_06_ordenacao_de_vetor()
{
        int resp;
        do{
        	        func_gen_limpa_tela();
        		    func_gen_titulo(" Menu Principal->ED-06",
                    " ",
                    "                                Ordenacao de Vetor de Struct Pelo Metodo BubbleSort", 31,
                    "                                               e Pesquisa Binaria(PB)",
                    "                       lendo dados no arquivo XML que estao inseridos no arquivo XML na TAD-05.");
        
		   			resp=func_06_01_sub_menu();
		}while(resp==0);	   		
}
void func_07_estrutura()
{
        int resp;
        do{
        	        func_gen_limpa_tela();
        		    func_gen_titulo(" Menu Principal->ED-07",
                    " ",
                    "                                              Manipulacao de estrutura", 31,
                    "                                             com leitura do arquivo XML",
                    " ");
        
		   			resp=func_07_01_sub_menu();
		}while(resp==0);    
}
void func_08_estrutura_complexa()
{
        int resp;
        do{
        	        func_gen_limpa_tela();
        		    func_gen_titulo(" Menu Principal->ED-08",
                    " ",
                    "                                          Manipulacao de estrutura complexa", 31,
                    "                                             com leitura do arquivo XML",
                    " ");
        
		   			resp=func_08_01_sub_menu();
		}while(resp==0);    
}
void func_09_arquivo_textual()
{
        int resp;
        do{
        	        func_gen_limpa_tela();
        		    func_gen_titulo(" Menu Principal->ED-09",
                    " ",
                    "                                           Arquivo Sequencial Textual", 31,
                    " ",
                    " ");
        
		   			resp=func_09_01_sub_menu();
		}while(resp==0);    
     
}
void func_10_arquivo_binario()
{
        int resp;
        do{
        	        func_gen_limpa_tela();
        		    func_gen_titulo(" Menu Principal->ED-10",
                    " ",
                    "                                           Arquivo Binario", 31,
                    " ",
                    " ");
		   			resp=func_10_01_sub_menu();
		}while(resp==0);         
}
void func_11_alocacao_estatica()
{
	    int resp;
        do{
        	        func_gen_limpa_tela();
        			func_gen_titulo("  Menu Principal->ED-11",
                    " ",
                	"                                            Alocacao Estatica", 31,
                    " ",
                    " "); 
					resp=func_11_01_sub_menu();
		}while(resp==0);     

     
}
void func_12_alocacao_dinamica()
{
         int resp;
        do{
        	        func_gen_limpa_tela();
        			func_gen_titulo("  Menu Principal->ED-12",
                    " ",
                	"                                            Alocacao Dinamica", 31,
                    " ",
                    " "); 
					resp=func_12_01_sub_menu();
		}while(resp==0);     
     
}
void func_13_lista_simples_e_dupla()
{
         int resp;
        do{
        	        func_gen_limpa_tela();
        		    func_gen_titulo(" Menu Principal->ED-13                                          ",
                         " ",
                         "                                               Lista Simples e Dupla", 31,
                         " ",
                         " ");  
					resp=func_13_01_sub_menu();
		}while(resp==0);
		 
		 
		 
		 
   
}

void func_14_recursividade_em_lista()
{
         func_gen_titulo("                                          Recursividade em Lista",
                         "                                                  ED -14",
                         "                                               EM CONSTRUCAO", 30,
                         "                           Não defini ainda este tema por nao possuir conhecimentos",
                         "                           suficientes para modelar a funcao");     
}
void func_15_pilha()
{
         func_gen_titulo("                                                  Pilha",
                         "                                                  ED -15",
                         "                                               EM CONSTRUCAO", 30,
                         "                           Não defini ainda este tema por nao possuir conhecimentos",
                         "                           suficientes para modelar a funcao");
     
}
void func_16_funcao_push_pop()
{
         func_gen_titulo("                                             Funcao Push-Pop",
                         "                                                  ED -16",
                         "                                               EM CONSTRUCAO", 30,
                         "                           Não defini ainda este tema por nao possuir conhecimentos",
                         "                           suficientes para modelar a funcao");
     
}
void func_17_fila()
{
         func_gen_titulo("                                                Funcao Fila",
                         "                                                  ED -17",
                         "                                               EM CONSTRUCAO", 30,
                         "                           Não defini ainda este tema por nao possuir conhecimentos",
                         "                           suficientes para modelar a funcao");
     
}
void func_18_funcao_enqueue_dequeue()
{
         func_gen_titulo("                                          Funcao enqueue dequeue",
                         "                                                  ED -18",
                         "                                               EM CONSTRUCAO", 30,
                         "                           Não defini ainda este tema por nao possuir conhecimentos",
                         "                           suficientes para modelar a funcao");
     
}
void func_19_fila_circular()
{
         func_gen_titulo("                                               Fila circular",
                         "                                                  ED -19",
                         "                                               EM CONSTRUCAO", 30,
                         "                           Não defini ainda este tema por nao possuir conhecimentos",
                         "                           suficientes para modelar a funcao");

     
}
void func_20_ordenacao_de_lista()
{
         func_gen_titulo("                                            Ordenacao de Lista",
                         "                                                  ED -20",
                         "                                               EM CONSTRUCAO", 30,
                         "                           Não defini ainda este tema por nao possuir conhecimentos",
                         "                           suficientes para modelar a funcao");
     
}    
                                      
/*
================================================================================
                          FUNCAO PRINCIPAL MAIN
================================================================================
*/     
int main()
{
    int resposta;
    resposta=0;
    func_gen_configurar_janela();//Setar Confiugurações da janela
    //Amarracao do Menu principal, so sai se digitar zero
    do{
            func_gen_limpa_tela();
            func_gen_titulo(" ",
                        " ",
                        "                                              CONSULTORIO MEDICO", 31,
                        " ",
                        " ");
            func_gen_menu();
            func_gen_linhap();
            printf("\n  Informe um numero:");
            scanf("%d", &resposta);
            fflush(stdin);
            switch(resposta)
            {             
                   case 0:
                        printf("\n  Deseja Reamente sair?\n  (0)-Sim\n  (1)Nao\n==>");
                        scanf("%d", &resposta);
                   break;
                   case 1:
                        func_gen_limpa_tela();
                        func_01_tema();
                        system("PAUSE");
                   break;
                   case 2:
                        func_gen_limpa_tela();
                        func_02_funcao();
                        system("PAUSE");
                   break; 
                   case 3:
                        func_gen_limpa_tela();
                        func_03_arquivo_xml();
                   break; 
                   case 4:
                        func_gen_limpa_tela();
                        func_04_arquivo();
                   break; 
                   case 5:
                        func_gen_limpa_tela();
                        func_05_vetor_matriz();
                   break; 
                   case 6:
                        func_gen_limpa_tela();
                        func_06_ordenacao_de_vetor();
                   break; 
                   case 7:
                        func_gen_limpa_tela();
                        func_07_estrutura();
                   break; 
                   case 8:
                        func_gen_limpa_tela();
                        func_08_estrutura_complexa();
                   break; 
                   case 9:
                        func_gen_limpa_tela();
                        func_09_arquivo_textual();
                        system("PAUSE");
                   break; 
                   case 10:
                        func_gen_limpa_tela();
                        func_10_arquivo_binario();
                   break; 
                   case 11:
                        func_gen_limpa_tela();
                        func_11_alocacao_estatica();
                   break; 
                   case 12:
                        func_gen_limpa_tela();
                        func_12_alocacao_dinamica();
                   break; 
                   case 13:
                        func_gen_limpa_tela();
                        func_13_lista_simples_e_dupla();
                        system("PAUSE");
                   break; 
                   case 14:
                        func_gen_limpa_tela();
                        func_14_recursividade_em_lista();
                        system("PAUSE");
                   break; 
                   case 15:
                        func_gen_limpa_tela();
                        func_15_pilha();
                        system("PAUSE");
                   break; 
                   case 16:
                        func_gen_limpa_tela();
                        func_16_funcao_push_pop();
                        system("PAUSE");
                   break; 
                   case 17:
                        func_gen_limpa_tela();
                        func_17_fila();
                        system("PAUSE");
                   break; 
                   case 18:
                        func_gen_limpa_tela();
                        func_18_funcao_enqueue_dequeue();
                        system("PAUSE");
                   break; 
                   case 19:
                        func_gen_limpa_tela();
                        func_19_fila_circular();
                        system("PAUSE");
                   break; 
                   case 20:
                        func_gen_limpa_tela();
                        func_20_ordenacao_de_lista();
                        system("PAUSE");
                   break; 
                   default:
                        resposta=21;
                   break;                                 
            }
      }while(resposta!=0);
}
