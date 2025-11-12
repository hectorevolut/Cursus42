" ────────────────────────────────────────────────
" Configuración avanzada de Vim para 42 Málaga
" Autor: Héctor Calderón (hecalder@student.42malaga.com)
" ────────────────────────────────────────────────

" ────────────────────────────────────────────────
" Plugins con vim-plug
" ────────────────────────────────────────────────
" Instala vim-plug si aún no lo tienes:
"   curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
call plug#begin('~/.vim/plugged')
  Plug '42Paris/42header'          " Cabecera estilo 42
  Plug 'preservim/nerdtree'        " Árbol de archivos
  Plug 'tpope/vim-commentary'      " Comentar líneas fácilmente con 'gc'
  Plug 'dense-analysis/ale'        " Linter/diagnóstico asíncrono
  Plug 'ghifarit53/tokyonight-vim'  " Tema TokyoNight
call plug#end()

" ────────────────────────────────────────────────
" Apariencia general
" ────────────────────────────────────────────────
set termguicolors
syntax on
set background=dark

" Opciones visuales generales
let mapleader=" "                           " Tecla líder (espacio)
set number                                  " Números de línea
set cursorline                              " Resalta línea actual
set nowrap                                  " No partir líneas largas
set scrolloff=3                             " Margen al desplazar
set showmatch                               " Resalta paréntesis o llaves coincidentes
set relativenumber                          " Números relativos (opcional)
set ruler                                   " Muestra posición del cursor

" ────────────────────────────────────────────────
" 42 Header
" ────────────────────────────────────────────────
let g:user42 = 'hecalder'
let g:mail42 = 'hecalder@student.42malaga.com'

" Atajo para insertar el header manualmente
nnoremap <leader>h :Stdheader<CR>

" Inserta o actualiza automáticamente el header en archivos C
augroup add_42_header
  autocmd!
  autocmd BufNewFile *.c,*.h :Stdheader
  autocmd BufWritePre *.c,*.h :Stdheader
augroup END

" ────────────────────────────────────────────────
" Calidad de vida en C
" ────────────────────────────────────────────────
set list
set listchars=tab:»·,trail:·

" Elimina espacios en blanco al guardar (solo en ciertos tipos de archivo)
augroup trim_trailing_ws
  autocmd!
  autocmd BufWritePre *.c,*.h,*.py %s/\s\+$//e
augroup END

" Sangrado oficial 42 — indentación con tabs (NO espacios)
set tabstop=4          " Cada tab equivale a 4 columnas
set softtabstop=4      " Tab y Backspace cuentan como 1 tab
set shiftwidth=4       " Indentación automática a 4 columnas
set noexpandtab        " Usa tabs reales (requisito 42)
set autoindent         " Mantiene indentación anterior
set smartindent        " Indentación inteligente para C
set smarttab           " Tab y Backspace respetan indentación

" ────────────────────────────────────────────────
" NERDTree
" ────────────────────────────────────────────────
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif
nnoremap <leader>n :NERDTreeToggle<CR>

" Cerrar Vim si solo queda NERDTree abierto
autocmd BufEnter * if (winnr('$') == 1 && exists('t:NERDTreeBufName') && bufname() == t:NERDTreeBufName) | quit | endif

" ────────────────────────────────────────────────
" ALE (linter y diagnóstico)
" ────────────────────────────────────────────────
let g:ale_lint_on_text_changed = 'always'
let g:ale_lint_on_insert_leave = 1
let g:ale_sign_error = '✗'
let g:ale_sign_warning = '•'
let g:ale_linters = { 'c': ['clang', 'gcc'] }
let g:ale_echo_msg_format = '[%linter%] %code: %s'
nmap <silent> [d <Plug>(ale_previous_wrap)
nmap <silent> ]d <Plug>(ale_next_wrap)

" ────────────────────────────────────────────────
" Comentarios rápidos
" ────────────────────────────────────────────────
" Usa gc para comentar/descomentar líneas o bloques
" Ejemplo: gcj (línea), gcip (párrafo), gcc (línea actual)

" ────────────────────────────────────────────────
" Portapapeles y búsqueda
" ────────────────────────────────────────────────
if has('clipboard')
  set clipboard=unnamedplus
endif

set ignorecase
set smartcase
set incsearch
set hlsearch
nnoremap <leader>/ :nohlsearch<CR>

" ────────────────────────────────────────────────
" Comodidad extra
" ────────────────────────────────────────────────
set wildmenu                              " Autocompletado de comandos
set laststatus=2                          " Barra de estado siempre visible
set showcmd                               " Muestra el comando en ejecución
set title                                 " Muestra el nombre del archivo en el título
set confirm                               " Confirma al cerrar archivos con cambios

" ────────────────────────────────────────────────
" Fin de configuración
" ────────────────────────────────────────────────
echo "Vim listo para 42 Málaga — Tema: TokyoNight Storm 🌙"



