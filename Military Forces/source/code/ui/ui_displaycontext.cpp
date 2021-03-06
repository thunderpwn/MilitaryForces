#include "ui_displaycontext.h"
#include "ui_local.h"



UI_DisplayContext::UI_DisplayContext()
{
	memset( &assets_, 0, sizeof(assets_) );
}


qhandle_t
UI_DisplayContext::registerShaderNoMip( const char* p )
{
	return refExport.RegisterShaderNoMip( p );
}

void
UI_DisplayContext::setColor( const float* v )
{
	refExport.SetColor( v );
}

void
UI_DisplayContext::drawStretchPic( float x, float y, float w, float h, 
								   float s1, float t1, float s2, float t2, qhandle_t hShader )
{
	refExport.DrawStretchPic( x, y, w, h, s1, t1, s2, t2, hShader );
}

qhandle_t
UI_DisplayContext::registerModel( const char *p )
{
	return refExport.RegisterModel( p );
}

void
UI_DisplayContext::modelBounds( qhandle_t model, vec3_t min, vec3_t max )
{
	refExport.ModelBounds( model, min, max );
}

void
UI_DisplayContext::clearScene()
{
	refExport.ClearScene();
}

void
UI_DisplayContext::addRefEntityToScene( const refEntity_t *re )
{
	refExport.AddRefEntityToScene( re );
}

void
UI_DisplayContext::renderScene( const refdef_t *fd )
{
	refExport.RenderScene( fd );
}

void
UI_DisplayContext::registerFont( const char *pFontname, int pointSize, fontInfo_t *font )
{
	refExport.RegisterFont( pFontname, pointSize, font );
}	

void
UI_DisplayContext::getCVarString( const char *cvar, char *buffer, int bufsize )
{
	Cvar_VariableStringBuffer( cvar, buffer, bufsize );
}

void
UI_DisplayContext::setCVar( const char *cvar, const char *value )
{
	Cvar_Set( cvar, value );
}

void
UI_DisplayContext::startLocalSound( sfxHandle_t sfx, int channelNum )
{
	S_StartLocalSound( sfx, channelNum );
}

//void
//UI_DisplayContext::Error( int level, const char *error, ... )
//{
//	Com_Error( level
//}

sfxHandle_t
UI_DisplayContext::registerSound( const char *name, bool compressed )
{
	return S_RegisterSound( name, compressed );
}

void
UI_DisplayContext::startBackgroundTrack( const char *intro, const char *loop )
{
	S_StartBackgroundTrack( intro, loop );
}

void
UI_DisplayContext::stopBackgroundTrack()
{
	S_StopBackgroundTrack();
}


















