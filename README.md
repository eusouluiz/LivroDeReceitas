# Livro de Receitas

> Este projeto foi desenvolvido durante a disciplina de Estruturas de Dados, no terceiro período do curso de Engenharia da Computação.

O projeto consistiu no desenvolvimento de um programa executado via terminal para o cadastro e visualização de receitas culinárias.
O projeto foi desenvolvido em liguagem C e a construção do programa se baseou no uso de listas duplamente encadeadas circulares.
Além disso, para uma exibição mais criativa e amigável ao usuário, uma interface baseada no formato de um livro físico foi criada utilizando caracteres ASCII para ser exibida no terminal e guiar o usuário em sua utilização.

-------- x -------- x -------- x -------- x -------- x -------- x -------- x -------- x -------- x -------- x -------- x -------- x --------

O programa tem como finalidade funcionar como um livro de receitas digital executável no prompt de comandos.
Ao ser iniciado o programa exibe a janela inicial, conforme a figura 1, com as opções de abrir o livro ou terminar a execução, fechando o programa.

Figura 1:

![image](https://user-images.githubusercontent.com/20136081/182543957-d99f797e-60b8-43b8-bede-50d489a8210b.png)

Ao ser aberto o livro um novo menu é exibido, contendo as receitas salvas durante o último uso, conforme a figura 2. Caso não hajam receitas salvas uma mensagem de ausência é exibida, de acordo com a figura 3.
Nesta tela algumas opções são disponibilizadas, como a navegação pelas receitas com o uso das setas do teclado, a inserção de uma nova receita ao livro pressionando a tecla ‘A’, a exclusão da receita presente na tela pressionando a tecla ‘X’, a alteração das informações da receita presente na tela pressionando a tecla ‘C’, a marcação de utilização com o uso da tecla Enter e o fechamento do livro pressionando a tecla ‘F’, sendo que este retorna à página de capa do livro.
Ao pressionar a tecla ‘A’ uma nova página é inserida ao livro, requisitando as informações de título, ingredientes, tempo de preparo, modo de preparo e autor da receita. Ao ser finalizada a coleta de dados, a página é posicionada respeitando ordem alfabética entre os títulos. Para cada uma das informações há um limite de caracteres e linhas, de acordo com a tabela 1.
Ao pressionar a tecla ‘X’ a receita presente na tela é excluída.

Figura 2:

![image](https://user-images.githubusercontent.com/20136081/182544065-2d30a6ba-a074-4a75-889d-959ab2a1d56d.png)


Figura 3:

![image](https://user-images.githubusercontent.com/20136081/182544075-81fa8486-9cde-457f-8fd2-a0ad277e1408.png)


Tabela 1:

![image](https://user-images.githubusercontent.com/20136081/182544199-7a5115ca-6d04-4224-a2ea-5201e1897439.png)

Ao pressionar a tecla ‘C’ um menu para seleção de informação a ser alterada é exibido, de acordo com a figura 4. A opção desejada deve ser selecionada com o uso das setas do teclado para mover a seta visível no terminal. Para confirmar a escolha a tecla Enter deve ser pressionada. Em seguida, a nova informação deve ser fornecida.

Figura 4:

![image](https://user-images.githubusercontent.com/20136081/182544256-307d4361-7811-4ca1-ae34-27899f2b7078.png)

Para marcar a utilização de uma receita a tecla Enter deve ser pressionada. Ao ser executada esta ação uma utilização será adicionada à receita, e a nota para ela será requisitada, sendo esta limitada de 0 a 10 unidades de avaliação.
Ao finalizar o uso do livro, ele pode ser fechado pressionando a tecla ‘F’, esta ação retorna para a tela inicial do programa. Na qual o programa pode ser finalizado com o acionamento da tela ‘F’ novamente, dessa forma os dados cadastrados serão salvos em arquivo e o programa será fechado.
