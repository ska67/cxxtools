/*
 * Copyright (C) 2007 Tommi Maekitalo
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * As a special exception, you may use this file as part of a free
 * software library without restriction. Specifically, if other files
 * instantiate templates or use macros or inline functions from this
 * file, or you compile this file and link it with other files to
 * produce an executable, this file does not by itself cause the
 * resulting executable to be covered by the GNU General Public
 * License. This exception does not however invalidate any other
 * reasons why the executable file might be covered by the GNU Library
 * General Public License.
 * 
 * This program is distributed in the hope that it will be useful, but
 * is provided AS IS, WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, and
 * NON-INFRINGEMENT.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */

#ifndef CXXTOOLS_PIPE_H
#define CXXTOOLS_PIPE_H

#include <unistd.h>

namespace cxxtools
{
  class Pipe
  {
      int fd[2];

      Pipe(const Pipe&);
      Pipe& operator= (const Pipe&);

    public:
      Pipe(bool doCreate = true)
      {
        if (doCreate)
          create();
      }

      ~Pipe();

      void create();

      int getReadFd() const   { return fd[0]; }
      int getWriteFd() const  { return fd[1]; }

      void closeReadFd();
      void closeWriteFd();

      void releaseReadFd()    { fd[0] = -1; }
      void releaseWriteFd()   { fd[1] = -1; }

      ssize_t write(const void* buf, size_t count);
      void write(char ch)
      {
        write(&ch, 1);
      }

      ssize_t read(void* buf, size_t count);
      char read();
  };
}

#endif // CXXTOOLS_PIPE_H
