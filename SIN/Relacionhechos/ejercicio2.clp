(deftemplate pacientes
	(slot nombre)
	(slot apellido)
	(slot dni)
	(slot seguroMedico)
)

(deftemplate visitas
	(slot fecha)
	(multislot sintomas)
	(slot pruebas)
	(slot medicacion)
	(slot dni)
)
