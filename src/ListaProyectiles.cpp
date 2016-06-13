#include "ListaProyectiles.h"


ListaProyectiles::ListaProyectiles(void)
{
}


ListaProyectiles::~ListaProyectiles(void)
{
	for(int i=0;i<lista.size();i++) 
	{
		delete lista[i];
		lista [i]=0;
	}
}

bool ListaProyectiles::agregar (Proyectil *ast) 
{ 
    lista.push_back(ast);    
    return true;    
} 

void ListaProyectiles::render(Camera cam) 
{ 
	
    for(int i=0;i<lista.size();i++)
	{
		if(lista[i]->move()) eliminarProyectil(i);
		else lista[i]->render(cam);      
	}
} 

void ListaProyectiles::eliminarProyectil(int ind) 
{ 
    if((ind<0)||(ind>=lista.size())) return;              
	
	//PROBLEMO
	//delete lista[ind];    
    //FIN PROBLEMO
	
	lista.erase(lista.begin() + ind);    
} 

void ListaProyectiles::event(SDL_Event* e, SDL_Rect selection, SDL_Point xyrel)
{
	for(int i = 0; i < lista.size(); i++) lista[i]->event(e, selection, xyrel);
}

bool ListaProyectiles::getSel(int ind)
{
	if(lista[ind]->getSel()) return true;
	else return false;
}

int ListaProyectiles::getSel()
{
	for(int i=0;i<lista.size();i++) if(getSel(i)) return i+1;
	return 0;
}


int ListaProyectiles::getSize()
{
	return lista.size();
}