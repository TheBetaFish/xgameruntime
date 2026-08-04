/*
 * Xbox Game runtime Library
 *
 * Written by Weather
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <initguid.h>
#include "private.h"

WINE_DEFAULT_DEBUG_CHANNEL(xgameruntime);

struct initialize_options
{
    UINT32 unk;
    BOOL isInline;
    const char *gameConfig;
};

HRESULT WINAPI InitializeApiImplEx2( ULONG gdkVer, ULONG gsVer, char mode, const struct initialize_options *options )
{
    TRACE( "gdkVer %ld, gsVer %ld, mode %d, options %p.\n", gdkVer, gsVer, mode, options );
    return S_OK;
}

HRESULT WINAPI InitializeApiImplEx( ULONG gdkVer, ULONG gsVer, char mode )
{
    return InitializeApiImplEx2( gdkVer, gsVer, mode, NULL );
}

HRESULT WINAPI InitializeApiImpl( ULONG gdkVer, ULONG gsVer )
{
    return InitializeApiImplEx2( gdkVer, gsVer, 0, NULL );
}

HRESULT WINAPI QueryApiImpl( REFCLSID clsid, REFIID iid, void **out )
{
    TRACE( "clsid %s, iid %s, out %p.\n", debugstr_guid( clsid ), debugstr_guid( iid ), out );
    return HRESULT_FROM_WIN32( ERROR_NOT_SUPPORTED );
}
