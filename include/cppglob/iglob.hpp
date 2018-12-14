/**
 * @file cppglob/iglob.hpp
 * @brief iglob() function declaration
 * @copyright 2018 Ryohei Machida
 *
 * @par License
 * @parblock
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * @endparblock
 */

#ifndef CPPGLOB_IGLOB_HPP
#define CPPGLOB_IGLOB_HPP

#include <cstddef>
#include <iterator>
#include <vector>
#include <filesystem>
#include "config.hpp"
#include "glob_iterator.hpp"
#include "escape.hpp"

namespace cppglob {
  /**
   * @brief Return an iterator which yields the paths matching a pathname
   * pattern.
   * @param pathname pattern string
   * @param recursive allow recursive pattern string
   *
   * The pattern may contain simple shell-style wildcards a la
   * fnmatch. However, unlike fnmatch, filenames starting with a
   * dot are special cases that are not matched by '*' and '?'
   * patterns.
   *
   * If recursive is true, the pattern '**' will match any files and
   * zero or more directories and subdirectories.
   */
  CPPGLOB_EXPORT glob_iterator iglob(const fs::path& pathname,
                                     bool recursive = false);

  /**
   * @brief Return the end of glob_iterator generated by
   * iglob(pathname, recursive) function.
   */
  CPPGLOB_EXPORT glob_iterator iglob();
}  // namespace cppglob

#endif
