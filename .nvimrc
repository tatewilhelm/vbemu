set exrc
set secure

nnoremap <F5> :make!<cr>:!./bin/vbemu "./bin/test_opcode.ch8" --chip-8<cr>
