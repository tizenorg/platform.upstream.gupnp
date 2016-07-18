Name: gupnp
Summary:    GUPnP is an framework for creating UPnP devices & control points
Version:    0.20.5
Release:    1
Group:      System/Libraries
License: LGPL-2.0+
URL:        http://www.gupnp.org/
Source0: %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  pkgconfig(gio-2.0)
BuildRequires:  pkgconfig(gmodule-2.0)
BuildRequires:  pkgconfig(gssdp-1.0)
BuildRequires:  pkgconfig(libsoup-2.4)
BuildRequires:  pkgconfig(libxml-2.0)
BuildRequires:  pkgconfig(uuid)
%if "%{profile}" == "ivi"
BuildRequires:  gobject-introspection-devel
BuildRequires:  vala
%endif


%description
GUPnP is an object-oriented open source framework for creating UPnP 
devices and control points, written in C using GObject and libsoup. 
The GUPnP API is intended to be easy to use, efficient and flexible.

%package devel
Summary:    Development package for gupnp
Group:      Development/Libraries
License:    LGPL-2.0+
Requires:   %{name} = %{version}-%{release}

%description devel
Files for development with gupnp.

%prep
%setup -q -n %{name}-%{version}
  
%build  
%if "%{profile}" == "ivi"
%configure --prefix=/usr --with-context-manager=network-manager --enable-introspection=yes
%else
%configure --prefix=/usr --with-context-manager=network-manager
%endif
  
make %{?jobs:-j%jobs}  
  
%install  
rm -rf %{buildroot}  
%make_install
rm -rf %{buildroot}/usr/share/gtk-doc
mkdir -p %{buildroot}/usr/share/license
cp COPYING %{buildroot}/usr/share/license/%{name}

%clean
rm -rf %{buildroot}

%post

%postun

%files
%defattr(-,root,root,-)
%doc
%{_libdir}/*.so.*
/usr/share/license/%{name}

%files devel
%defattr(-,root,root,-)
/usr/bin/gupnp-binding-tool
/usr/include/gupnp-1.0/*
#/usr/lib/*.a
%{_libdir}/*.so
%{_libdir}/pkgconfig/*
%if "%{profile}" == "ivi"
%{_datadir}/gir-1.0/GUPnP-1.0.gir
%{_libdir}/girepository-1.0/GUPnP-1.0.typelib
%{_datadir}/vala/vapi/gupnp-1.0.deps
%{_datadir}/vala/vapi/gupnp-1.0.vapi
%endif
