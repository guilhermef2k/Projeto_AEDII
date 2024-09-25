<h1  align="center">
  Distribuidora Ponteiro sem Ponta
</h1>

<h1 align="center">
  <img  src="https://live.staticflickr.com/65535/53994772090_761d90f09c_z.jpg"  alt="Ponteiro Sem Ponta"  height="250"  width="250">
  <br>
</h1>

<p  align="center">
  <a  href="(https://github.com/guilhermef2k/Projeto_AEDII/tags/)">
  <img  src="https://img.shields.io/github/tag/guilhermef2k/Projeto_AEDII">
  </a>
  <a  href="https://GitHub.com/guilhermef2k/Projeto_AEDII/commit/">
  <img  src="https://badgen.net/github/commits/guilhermef2k/Projeto_AEDII">
  </a>
  <a  href="https://GitHub.com/guilhermef2k/Projeto_AEDII/pull/">
  <img  src="https://img.shields.io/github/issues-pr/guilhermef2k/Projeto_AEDII">
  </a>
  <a  href="https://GitHub.com/guilhermef2k/Projeto_AEDII/graphs/contributors/">
  <img  src="https://badgen.net/github/contributors/guilhermef2k/Projeto_AEDII">
  </a>
  <a  href="https://GitHub.com/guilhermef2k/Projeto_AEDII/stargazers/">
  <img  src="https://img.shields.io/github/stars/guilhermef2k/Projeto_AEDII.svg?style=social&label=Stars&maxAge=2592000)">
  </a>
</p>

<p  align="center">
  <a>
  <img  src="http://img.shields.io/static/v1?label=status&message=EM%20DESENVOLVIMENTO&color=GREEN&style=badge)">
  </a>
</p>

## Introdução

Ponteiro sem ponta é o nome dado ao projeto que visa a criação, em linguagem C, de um sistema de gestão para distribuidoras, voltado para simplificar e automatizar as operações de empresas que atuam na distribuição de produtos. Este sistema visa reduzir custos, aumentar a produtividade e aprimorar a experiência do cliente. 

## Tabela de Conteúdos 
<!--ts-->
*	[Introdução](#introdução) 
*	[Tabela de Conteúdo](#tabela-de-conteúdos) 
*	[Funcionalidades](#-funcionalidades) 
*	[Execução](#execução) 
	*	[Pré-requisitos](#-pré-requisitos) 
	*	[Instalação](#-instalação) 
	*	[Compilação e execução](#%EF%B8%8F-compilação-e-execução) 
*	[Colaboradores](#-colaboradores) 
<!--te-->

### ✨ Funcionalidades

Básicas:

- [x] Login 
- [ ] Cadastrar novo usuário 
- [ ] Consultar estoque
- [ ] Buscar produtos
- [ ] Mostrar produtos por categoria

Após cadastro e login:

- [ ] Cadastrar novo produto
- [ ] Editar produto
- [ ] Excluir produto
- [ ] Excluir usuário
- [ ] Ordenar produtos por código

## Execução

### 💻 Pré-requisitos

Para execução deste sistema é necessário atender os seguintes **requisitos**:

* Possuir um computador funcional.
* O computador possui um compilador C instalado.
* O git está instalado em sua máquina (caso queira clonar o repositório).
  
### 🔧 Instalação

Para ter o sistema em sua máquina siga os passos a seguir. 
* Selecione uma pasta para receber os arquivos e abra esta pasta no terminal **Git Bash** (click com o botão direito e “*Git Bash Here*”).
* Em seguida basta executar os comandos:

	`git clone https://github.com/guilhermef2k/Projeto_AEDII.git`

	`cd Projeto_AEDII`

Feito isso o sistema já estará em sua máquina pronto para ser compilado e executado.

### ⚙️ Compilação e execução

Para **compilar** e **executar** o sistema basta colar os comandos a seguir um por vez no terminal e teclar *enter*.

`cd src`

`gcc -ansi -Wall -pedantic-errors -g -c main.c`

`gcc -ansi -Wall -pedantic-errors -g -c distribuidora.c`

`gcc main.o distribuidora.o -lm -o Projeto`

Após isso, será gerado na pasta do projeto um executável que pode ser aberto clicando duas vezes com o botão esquerdo ou executando o comando `.\Projeto` no terminal.

> [!NOTE]
> Em alguns terminais como o Git Bash o comando para abrir o executável é `./Projeto`. 

### 🤝 Colaboradores
* **Guilherme Vasconcelos** - *Documentação* - [guilhermef2k](https://github.com/guilhermef2k)
* **Harley Lucas** - *Codificador* - [harleylsb](https://github.com/harleylsb)
* **José Veríssimo** - *Testador* - [JV-ANUBIS](https://github.com/JV-ANUBIS)
* **Alex Bruno** - *Redator* - [alexb7z](https://github.com/alexb7z)
