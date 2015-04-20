(deftemplate trayectos_aereos
	(slot origen)
	(slot destino)
)
;v1
(assert(trayectos_aereos(origen Lisboa)(destino Paris)))
(assert(trayectos_aereos(origen Estocolmo)(destino Paris)))
(assert(trayectos_aereos(origen Lisboa)(destino Madrid)))
(assert(trayectos_aereos(origen Roma)(destino Madrid)))
(assert(trayectos_aereos(origen Roma)(destino Lisboa)))
(assert(trayectos_aereos(origen Paris)(destino Roma)))
(assert(trayectos_aereos(origen Frankfurt)(destino Roma)))
(assert(trayectos_aereos(origen Roma)(destino Frankfurt)))
(assert(trayectos_aereos(origen Frankfurt)(destino Estocolmo)))

;v2
(deffacts datos
	(trayectos_aereos(origen Lisboa)(destino Paris))
	(trayectos_aereos(origen Estocolmo)(destino Paris))
	(trayectos_aereos(origen Lisboa)(destino Madrid))
	(trayectos_aereos(origen Roma)(destino Madrid))
	(trayectos_aereos(origen Roma)(destino Lisboa))
	(trayectos_aereos(origen Paris)(destino Roma))
	(trayectos_aereos(origen Frankfurt)(destino Roma))
	(trayectos_aereos(origen Roma)(destino Frankfurt))
	(trayectos_aereos(origen Frankfurt)(destino Estocolmo))
)
