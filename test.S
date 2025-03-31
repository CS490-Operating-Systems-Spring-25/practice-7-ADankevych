.section .data
    buffer:
        .fill 256, 1, 0
    filename:
        .asciz "test.txt"
    content:
        .asciz "Hello!\n"

.section .text
    .global _start

_start:
    // Use getcwd to retrieve current dir
    ldr x0, =buffer
    mov x1, #256
    mov x8, #17
    svc #0

    // Print dir
    mov x0, #1
    ldr x1, =buffer
    mov x2, #256
    mov x8, #64
    svc #0

    // Create file
    mov x0, #-100
    ldr x1, =filename
    mov x2, #0x241
    mov x3, #0644
    mov x8, #56
    svc #0
    mov x9, x0

    // Write content to file
    mov x0, x9
    ldr x1, =content
    mov x2, #7
    mov x8, #64
    svc #0

    // Close file
    mov x0, x9
    mov x8, #57
    svc #0

    // Chmod
    ldr x0, =filename
    mov x1, #0755
    mov x8, #52
    svc #0

    // Open file to read
    ldr x0, =filename
    mov x1, #0
    mov x8, #56
    svc #0
    mov x9, x0

    // Read file content
    mov x0, x9
    ldr x1, =buffer
    mov x2, #256
    mov x8, #63
    svc #0
    mov x10, x0

    // Close file
    mov x0, x9
    mov x8, #57
    svc #0

    // Exit with 1
    mov x0, #1
    mov x8, #93
    svc #0
