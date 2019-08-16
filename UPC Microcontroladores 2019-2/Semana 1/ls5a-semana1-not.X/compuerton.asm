;Este es un comentario
;Programa hecho por Kalun Lau
;UPC San Miguel
;16 de agosto del 2019
    
    list p=18f4550	    ;Modelo del microcontrolador
    #include <p18f4550.inc>	    ;Libreria de nombre de registros
    
;Aqui deben de declararse los bits de configuracion (directivas de preprocesador)    
    CONFIG  FOSC = XT_XT          ; Oscillator Selection bits (XT oscillator (XT))
    CONFIG  PWRT = ON             ; Power-up Timer Enable bit (PWRT enabled)
    CONFIG  BOR = OFF             ; Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
    CONFIG  WDT = OFF             ; Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
    CONFIG  PBADEN = OFF          ; PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
    CONFIG  LVP = OFF             ; Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

  org 0x0000		    ;Vector de RESET
    goto confeg
    
    org 0x0020		    ;Zona de programa de usuario
confeg:
    bcf TRISD, 0	    ;Puerto RD0 como salida
			    ;Los puertos que son entradas no se
			    ;necesitan declarar
inicio:
    btfss PORTB, 0	    ;Pregunto si RB0 es igual a uno
    goto falsaso	    ;Salta aqui si es falso
    bcf LATD, 0		    ;Salta aqui si es verdadero y pone a cero el puerto RD0
    goto inicio		    ;Salta a la etiqueta inicio
falsaso:
    bsf LATD, 0		    ;Pone a uno el puerto RD0
    goto inicio		    ;Salta a la etiqueta inicio
    end			    ;Fin del programa
    


