Algoritmo "papa-papa"

Var

   n: real
   ind: logico
   i, j, k, vida, joga: inteiro
   lin, col, _lin, _col, lin_ant, col_ant: inteiro

   dir: vetor[1..2, 1..5] de inteiro
   mat: vetor[1..9, 1..9] de caracter

Inicio

   //inicializacao das direcoes validas
   dir[1,1] <- 0
   dir[2,1] <- 0
   n <- 1.0
   para j de 2 ate 5 faca
      dir[1,j] <- int(sen((-n*PI)/2.0))
      dir[2,7-j] <- dir[1,j]
      n <- n + 1.0
   fimpara

   //inicializacao da matriz principal
   para i de 1 ate 9 faca
      para j de 1 ate 9 faca
         mat[i,j] <- " "
      fimpara
   fimpara

   mat[5,5] <- "o"

   //gerarcao de posicoes para '-'
   i <- 0
   enquanto (i < 40) faca
      lin <- randi(9)+1
      col <- randi(9)+1
      se (mat[lin,col] = " ") entao
         mat[lin,col] <- "-"
         i <- i+1
      fimse
   fimenquanto

   //funcionalidades do jogo
   vida <- 1
   joga <- 0

   lin_ant <- 5
   col_ant <- 5

   escreval("--------------------------------------")
   repita
      escreva("VIDA: ", vida, "          | ")
      escreval("JOGADAS: ", joga)

      escreval("    1   2   3   4   5   6   7   8   9")
      para i de 1 ate 9 faca
         escreva(i, " ")
         para j de 1 ate 9 faca
            escreva("[", mat[i,j], "] ")
         fimpara
         escreval()
      fimpara

      escreva("LINHA: ")
      leia(lin)
      escreva("COLUNA: ")
      leia(col)

      ind <- falso
      para k de 1 ate 5 faca
         _lin <- lin_ant + dir[1,k]
         _col <- col_ant + dir[2,k]
         se (1 <= _col) e (_col <= 9) e (1 <= _lin) e (_lin <= 9) e (_lin = lin) e (_col = col) entao
            ind <- verdadeiro
         fimse
      fimpara

      se (ind = falso) entao
         interrompa
      fimse

      se (mat[lin,col] = "-") entao
         vida <- vida + 1
      senao
         vida <- vida - 1
      fimse

      mat[lin_ant, col_ant] <- " "
      mat[lin,col] <- "o"

      lin_ant <- lin
      col_ant <- col

      joga <- joga + 1

      escreval("--------------------------------------")

   ate (vida = 0) ou (joga > 40) faca

   escreval()

   se (ind = falso) entao
      escreval("GAME OVER: Posicao Invalida")
   fimse

   se (vida = 0) entao
      escreval("GAME OVER: Vidas Acabaram")
   fimse

   se (joga > 40) entao
      escreval("GAME OVER: Jogadas Acabaram")
   fimse

Fimalgoritmo