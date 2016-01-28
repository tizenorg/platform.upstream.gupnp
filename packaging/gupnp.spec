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
BuildRequires:  gobject-introspection-devel
BuildRequires:  vala


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
%configure --with-context-manager=network-manager --disable-static

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install
mkdir -p %{buildroot}%{_datadir}/license
cp COPYING %{buildroot}%{_datadir}/license/%{name}
rm -rf  %{buildroot}%{_datadir}/gtk-doc

%clean
rm -rf %{buildroot}

%post

%postun

%files
%defattr(-,root,root,-)
%doc
%{_libdir}/*.so.*
%{_datadir}/license/%{name}

%files devel
%defattr(-,root,root,-)
%{_bindir}/gupnp-binding-tool
%{_includedir}/gupnp-1.0/*
%{_libdir}/*.so
%{_libdir}/pkgconfig/gupnp-1.0.pc
%{_libdir}/girepository-1.0/GUPnP-1.0.typelib
%{_datadir}/gir-1.0/GUPnP-1.0.gir
%{_datadir}/vala/vapi/gupnp-1.0.deps
%{_datadir}/vala/vapi/gupnp-1.0.vapi

