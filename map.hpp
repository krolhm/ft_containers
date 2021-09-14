/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:45:26 by rbourgea          #+#    #+#             */
/*   Updated: 2021/09/14 11:31:24 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>
# include <iostream>
# include <cstring>
# include "common/others.hpp"
# include "common/random_access_iterator.hpp"
# include "common/reverse_iterator.hpp"
# include "common/lexicographical_compare.hpp"
# include "common/iterator.hpp"
# include "common/iterator_traits.hpp"
# include "common/enable_if.hpp"
# include "common/is_integral.hpp"
# include "common/binary_search_tree.hpp"
# include "common/pair.hpp"

// namespace ft
// {
// 	template <class Key,								  			// map::key_type
// 			  class T,									  			// map::mapped_type
// 			  class Compare = ft::less<Key>,						// map::key_compare
// 			  class Alloc = std::allocator<ft::pair<const Key, T> >	// map::allocator_type
// 			  >
// 	class map
// 	{
// 		public:
// 			typedef Key											key_type;
// 			typedef T											mapped_type;
// 			typedef ft::pair<key_type, mapped_type> 			value_type;
// 			typedef Compare										key_compare;

// 			class value_compare : ft::binary_function<value_type, value_type, bool>
// 			{ // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
// 				friend class map<key_type, mapped_type, key_compare, Alloc>;

// 				protected:
// 					Compare comp;
// 					value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
// 				public:
// 					typedef bool result_type;
// 					typedef value_type first_argument_type;
// 					typedef value_type second_argument_type;
// 					bool operator()(const value_type &x, const value_type &y) const
// 					{
// 						return comp(x.first, y.first);
// 					}
// 			};

// 			typedef Alloc										allocator_type;
// 			typedef typename allocator_type::reference			reference;
// 			typedef typename allocator_type::const_reference	const_reference;
// 			typedef typename allocator_type::pointer		 	pointer;
// 			typedef typename allocator_type::const_pointer		const_pointer;
// 			typedef typename ft::binary_search_tree<value_type, key_compare>::iterator iterator;
// 			typedef typename ft::binary_search_tree<value_type, key_compare>::const_iterator const_iterator;
// 			typedef typename ft::reverse_iterator<iterator>		reverse_iterator;
// 			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
// 			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
// 			typedef size_t										size_type;
			
// 			// Constructors:
// 			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
// 				: _alloc(alloc), _comp(comp), _bst()
// 			{

// 			}
			
// 			template <class InputIterator> 
// 			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
// 				: _alloc(alloc), _comp(comp), _bst()
// 			{
// 				bool is_valid;
// 				if (!(is_valid = ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
// 					throw (ft::InvalidIteratorException<typename ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());
// 				insert(first, last);
// 			}

// 			map(const map& x) : _alloc(x._alloc), _comp(x._comp), _bst()
// 			{
// 				insert(x.begin(), x.end());
// 			}

// 			~map()
// 			{
// 				clear();
// 			}

// 			// Operators:
// 			map &operator=(const map &x)
// 			{
// 				if (&x == this)
// 					return (*this);
// 				clear();
// 				insert(x.begin(), x.end());
// 				return (*this);
// 			}

// 			// Iterators:
// 			iterator begin()
// 			{
// 				return (iterator(_bst._last_node->left, _bst._last_node));
// 			}
// 			const_iterator begin() const
// 			{
// 				return (const_iterator(_bst._last_node->left, _bst._last_node));
// 			}
// 			iterator end()
// 			{
// 				return (iterator(_bst._last_node, _bst._last_node));
// 			}
// 			const_iterator end() const
// 			{
// 				return (const_iterator(_bst._last_node, _bst._last_node));
// 			}
// 			reverse_iterator rbegin()
// 			{ 
// 				return (reverse_iterator(end()));
// 			}
// 			const_reverse_iterator rbegin() const
// 			{
// 				return (const_reverse_iterator(end()));
// 			}
// 			reverse_iterator rend()
// 			{
// 				return (reverse_iterator(begin()));
// 			}
// 			const_reverse_iterator rend() const
// 			{
// 				return (const_reverse_iterator(begin()));
// 			}
			
// 			// Capacity:
// 			bool empty() const
// 			{
// 				return (_bst._last_node->parent == _bst._last_node);
// 			}
// 			size_type size() const
// 			{
// 				return (_bst._last_node->value.first);
// 			}
// 			size_type max_size() const
// 			{ 
// 				return (_bst.max_size());
// 			}

// 			// Element access:
// 			mapped_type &operator[](const key_type &k)
// 			{
// 				iterator tmp = find(k);

// 				if (tmp == end())
// 					insert(ft::make_pair(k, mapped_type()));
// 				tmp = find(k);
// 				return ((*tmp).second);
// 			}
			
// 			// Modifiers:
// 			pair<iterator, bool> insert(const value_type &val)
// 			{
// 				return (_bst.insertPair(val));
// 			}
// 			iterator insert(iterator position, const value_type &val)
// 			{
// 				(void)position;
// 				return (_bst.insertPair(val).first);
// 			}
// 			template <class InputIterator>
// 			void insert (InputIterator first, InputIterator last,
// 				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
// 			{
// 				bool is_valid;
// 				if (!(is_valid = ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
// 					throw (ft::InvalidIteratorException<typename ft::is_input_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());

// 				difference_type n = ft::distance(first, last);
// 				while (n--)
// 					insert(*(first++));
// 			}
// 			void erase (iterator position)
// 			{
// 				erase((*position).first);
// 			}
// 			size_type erase(const key_type &k)
// 			{
// 				if (find(k) == end())
// 					return (0);
// 				_bst.removeByKey(ft::make_pair(k, mapped_type()));
// 				return (1);
// 			}
// 			void erase(iterator first, iterator last)
// 			{
// 				while (first != last)
// 					erase((*(first++)).first);
// 			}
// 			void swap(map &x)
// 			{
// 				_bst.swap(x._bst);
// 			}
// 			void clear()
// 			{
// 				erase(begin(), end());
// 			}

// 			// Observers:
// 			key_compare key_comp() const
// 			{
// 				return (key_compare());
// 			}
// 			value_compare value_comp() const
// 			{
// 				return (value_compare(key_compare()));
// 			}
			
// 			// Operations:
// 			iterator find(const key_type &k)
// 			{
// 				return (iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node));
// 			}
// 			const_iterator find(const key_type &k) const
// 			{
// 				return (const_iterator(_bst.searchByKey(ft::make_pair(k, mapped_type())), _bst._last_node));
// 			}
// 			size_type count(const key_type &k) const
// 			{
// 				const_iterator beg = begin();
// 				const_iterator end = end();

// 				while (beg != end)
// 					if ((*(beg++)).first == k)
// 						return (1);
// 				return (0);
// 			}
// 			const_iterator lower_bound(const key_type &k) const
// 			{
// 				return (const_iterator(lower_bound(k)));
// 			}
// 			iterator upper_bound(const key_type &k)
// 			{
// 				iterator beg = begin();
// 				iterator end = end();

// 				while (beg != end)
// 				{
// 					if (_comp(k, (*beg).first))
// 						break;
// 					beg++;
// 				}
// 				return (beg);
// 			}
// 			const_iterator upper_bound(const key_type &k) const
// 			{
// 				return (const_iterator(upper_bound(k)));
// 			}
// 			ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
// 			{ 
// 				return (ft::make_pair(lower_bound(k), upper_bound(k)));
// 			}
// 			ft::pair<iterator, iterator> equal_range (const key_type& k)
// 			{ 
// 				return (ft::make_pair(lower_bound(k), upper_bound(k)));
// 			}

// 			private:
// 				allocator_type							_alloc;
// 				Compare									_comp;
// 				binary_search_tree<value_type, Compare>	_bst;
// 	};
// }


namespace ft {

    template<class Key, class T, class Compare = std::less<Key>,
            class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map {

    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef Alloc allocator_type;

    private:
        static const int NODE_CREATION_SIZE = 1;

        struct node {
            size_type size;
            pointer value;
            node *root;
            node *left_node;
            node *right_node;
            node *end_node;
            bool is_end_node;

            node &operator=(const node &n) {
                this->root = n.root;
                this->left_node = n.left_node;
                this->right_node = n.right_node;
                this->end_node = n.end_node;
                this->size = n.size;
                this->value = n.value;
                this->is_end_node = n.is_end_node;
                return *this;
            };
        };

        class value_compare : public std::binary_function<value_type, value_type, bool> {
        public:
            bool operator()(const value_type &v1, const value_type &v2) const { return comp(v1.first, v2.first); };
        public:
            key_compare compare;

            explicit value_compare(key_compare comp) : compare(comp) {};
        };

        size_type tree_size;
        node *root;
        node *begin_node;
        node *end_node;
        node *true_end_node;
        key_compare comparator;
        typedef typename allocator_type::template rebind<node>::other node_allocator_rebind;
        node_allocator_rebind node_allocator;
        allocator_type alloc;
    public:
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : tree_size(0), root(NULL),
                                                                       begin_node(NULL),
                                                                       end_node(create_end_node()), true_end_node(NULL),
                                                                       comparator(comp), alloc(alloc) {
        }

        template<class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type(),
            typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type * = 0) : tree_size(0),
                                                                                                  root(NULL),
                                                                                                  begin_node(NULL),
                                                                                                  end_node(
                                                                                                          create_end_node()),
                                                                                                  true_end_node(NULL),
                                                                                                  comparator(comp),
                                                                                                  alloc(alloc) {
            insert(first, last);
        }

        map(const map &x) : tree_size(0), root(NULL),
                            begin_node(NULL),
                            end_node(create_end_node()), true_end_node(NULL), comparator(x.comparator), alloc(x.alloc) {
            const_iterator f = x.begin();
            for (; f != x.end(); f++)
                insert(*f);
        }

        ~map() {
            if (tree_size > 0)
                clear();
            node_allocator.deallocate(end_node, NODE_CREATION_SIZE);
        }

        class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
        private:

            node *get_next(node *cur_node) {
                node *next_max = find_next_element(cur_node);
                if (next_max != NULL && next_max->value->first > i_node->value->first &&
                    (cur_node == i_node || next_max->value->first < cur_node->value->first ||
                     cur_node->value->first < i_node->value->first))
                    return next_max;
                if (cur_node->value->first > i_node->value->first)
                    return cur_node;
                return NULL;
            }

            node *get_prev(node *cur_node) {
                node *nearest_max = find_prev_element(cur_node);
                if (nearest_max != NULL && nearest_max->value->first < i_node->value->first &&
                    (cur_node == i_node || nearest_max->value->first > cur_node->value->first ||
                     cur_node->value->first > i_node->value->first))
                    return nearest_max;
                if (cur_node->value->first < i_node->value->first)
                    return cur_node;
                return NULL;
            }

            node *find_next_element(node *cur_node) {
                node *max_left = NULL;
                node *max_right = NULL;
                if (cur_node == NULL || i_node == NULL)
                    return NULL;
                if (cur_node->left_node != NULL)
                    max_left = get_next(cur_node->left_node);
                if (cur_node->right_node != NULL)
                    max_right = get_next(cur_node->right_node);
                if (cur_node != i_node && cur_node->value->first > i_node->value->first &&
                    ((max_left != NULL && (cur_node->value->first < max_left->value->first &&
                                           (max_right == NULL || cur_node->value->first < max_right->value->first)))
                     || (max_right != NULL && (cur_node->value->first < max_right->value->first &&
                                               (max_left == NULL ||
                                                cur_node->value->first < max_left->value->first))) ||
                     (max_left == NULL && max_right == NULL)))
                    return cur_node;
                if ((max_left == NULL && max_right != NULL) ||
                    (max_right != NULL && max_left != NULL &&
                     max_right->value->first < max_left->value->first))
                    return max_right;
                if ((max_right == NULL && max_left != NULL) ||
                    (max_right != NULL && max_left != NULL &&
                     max_left->value->first < max_right->value->first))
                    return max_left;
                return NULL;
            }

            node *find_prev_element(node *cur_node) {
                node *nearest_left = NULL;
                node *nearest_right = NULL;
                if (cur_node == NULL || i_node == NULL)
                    return NULL;
                if (cur_node->left_node != NULL)
                    nearest_left = get_prev(cur_node->left_node);
                if (cur_node->right_node != NULL)
                    nearest_right = get_prev(cur_node->right_node);
                if (cur_node != i_node && cur_node->value->first < i_node->value->first &&
                    ((nearest_left != NULL && (cur_node->value->first > nearest_left->value->first &&
                                               (nearest_right == NULL ||
                                                cur_node->value->first > nearest_right->value->first)))
                     || (nearest_right != NULL && (cur_node->value->first > nearest_right->value->first &&
                                                   (nearest_left == NULL ||
                                                    cur_node->value->first > nearest_left->value->first))) ||
                     (nearest_left == NULL && nearest_right == NULL)))
                    return cur_node;
                if (nearest_right != NULL &&
                    (nearest_left == NULL ||
                     nearest_right->value->first > nearest_left->value->first))
                    return nearest_right;
                if (nearest_left != NULL &&
                    (nearest_right == NULL ||
                     nearest_left->value->first > nearest_right->value->first))
                    return nearest_left;
                return NULL;
            }

        public:
            node *i_node;

            iterator() {};

            iterator(node *node) : i_node(node) {}

            iterator(const iterator &iter) { *this = iter; };

            ~iterator() {};

            reference operator*() const { return *(this->i_node->value); }

            iterator operator++() {
                node *end = i_node->end_node;
                i_node = find_next_element(i_node->root);
                if (i_node == NULL)
                    i_node = end;
                return *this;
            }

            iterator operator--() {
                if (i_node->is_end_node)
                    i_node = i_node->left_node;
                else
                    i_node = find_prev_element(i_node->root);
                return *this;
            }

            iterator operator++(int) {
                iterator iter(*this);
                node *end = i_node->end_node;
                i_node = find_next_element(i_node->root);
                if (i_node == NULL)
                    i_node = end;
                return iter;
            }

            iterator operator--(int) {
                iterator iter(*this);
                if (i_node->is_end_node)
                    i_node = i_node->left_node;
                else
                    i_node = find_prev_element(i_node->root);
                return iter;
            }

            pointer operator->() { return i_node->value; }

            bool operator==(const iterator &i) const { return i_node == i.i_node; }

            bool operator!=(const iterator &i) const { return i_node != i.i_node; }

            iterator &operator=(const iterator &iter) {
                this->i_node = iter.i_node;
                return *this;
            };
        };

        class const_iterator
                : public std::iterator<std::bidirectional_iterator_tag, T> {
        private:
            node *get_next(node *cur_node) {
                node *next_max = find_next_element(cur_node);
                if (next_max != NULL && next_max->value->first > i_node->value->first &&
                    (cur_node == i_node || next_max->value->first < cur_node->value->first ||
                     cur_node->value->first < i_node->value->first))
                    return next_max;
                if (cur_node->value->first > i_node->value->first)
                    return cur_node;
                return NULL;
            }

            node *get_prev(node *cur_node) {
                node *nearest_max = find_prev_element(cur_node);
                if (nearest_max != NULL && nearest_max->value->first < i_node->value->first &&
                    (cur_node == i_node || nearest_max->value->first > cur_node->value->first ||
                     cur_node->value->first > i_node->value->first))
                    return nearest_max;
                if (cur_node->value->first < i_node->value->first)
                    return cur_node;
                return NULL;
            }

            node *find_next_element(node *cur_node) {
                node *max_left = NULL;
                node *max_right = NULL;
                if (cur_node == NULL || i_node == NULL)
                    return NULL;
                if (cur_node->left_node != NULL)
                    max_left = get_next(cur_node->left_node);
                if (cur_node->right_node != NULL)
                    max_right = get_next(cur_node->right_node);
                if (cur_node != i_node && cur_node->value->first > i_node->value->first &&
                    ((max_left != NULL && (cur_node->value->first < max_left->value->first &&
                                           (max_right == NULL || cur_node->value->first < max_right->value->first)))
                     || (max_right != NULL && (cur_node->value->first < max_right->value->first &&
                                               (max_left == NULL ||
                                                cur_node->value->first < max_left->value->first))) ||
                     (max_left == NULL && max_right == NULL)))
                    return cur_node;
                if ((max_left == NULL && max_right != NULL) ||
                    (max_right != NULL && max_left != NULL &&
                     max_right->value->first < max_left->value->first))
                    return max_right;
                if ((max_right == NULL && max_left != NULL) ||
                    (max_right != NULL && max_left != NULL &&
                     max_left->value->first < max_right->value->first))
                    return max_left;
                return NULL;
            }

            node *find_prev_element(node *cur_node) {
                node *nearest_left = NULL;
                node *nearest_right = NULL;
                if (cur_node == NULL || i_node == NULL)
                    return NULL;
                if (cur_node->left_node != NULL)
                    nearest_left = get_prev(cur_node->left_node);
                if (cur_node->right_node != NULL)
                    nearest_right = get_prev(cur_node->right_node);
                if (cur_node != i_node && cur_node->value->first < i_node->value->first &&
                    ((nearest_left != NULL && (cur_node->value->first > nearest_left->value->first &&
                                               (nearest_right == NULL ||
                                                cur_node->value->first > nearest_right->value->first)))
                     || (nearest_right != NULL && (cur_node->value->first > nearest_right->value->first &&
                                                   (nearest_left == NULL ||
                                                    cur_node->value->first > nearest_left->value->first))) ||
                     (nearest_left == NULL && nearest_right == NULL)))
                    return cur_node;
                if (nearest_right != NULL &&
                    (nearest_left == NULL ||
                     nearest_right->value->first > nearest_left->value->first))
                    return nearest_right;
                if (nearest_left != NULL &&
                    (nearest_right == NULL ||
                     nearest_left->value->first > nearest_right->value->first))
                    return nearest_left;
                return NULL;
            }

        public:
            node *i_node;

            explicit const_iterator(node *it = nullptr) : i_node(it) {};

            const_iterator(const const_iterator &it) { *this = it; };

            const_iterator(const iterator &it) { *this = it; };

            ~const_iterator() {};

            reference operator*() const { return *(i_node->value); }

            pointer operator->() const { return i_node->value; }

            const_iterator operator++() {
                node *end = i_node->end_node;
                i_node = find_next_element(i_node->root);
                if (i_node == NULL)
                    i_node = end;
                return *this;
            }

            const_iterator operator--() {
                if (i_node->is_end_node)
                    i_node = i_node->left_node;
                else
                    i_node = find_prev_element(i_node->root);
                return *this;
            }

            const_iterator operator++(int) {
                const_iterator iter(*this);
                node *end = i_node->end_node;
                i_node = find_next_element(i_node->root);
                if (i_node == NULL)
                    i_node = end;
                return iter;
            }

            const_iterator operator--(int) {
                const_iterator iter(*this);
                if (i_node->is_end_node)
                    i_node = i_node->left_node;
                else
                    i_node = find_prev_element(i_node->root);
                return iter;
            }

            bool operator==(const iterator &i) const { return i_node == i.i_node; }

            bool operator!=(const iterator &i) const { return i_node != i.i_node; }

            bool operator==(const const_iterator &it) const { return this->i_node == it.i_node; };

            bool operator!=(const const_iterator &it) const { return this->i_node != it.i_node; };

            const_iterator &operator=(const const_iterator &it) {
                this->i_node = it.i_node;
                return *this;
            };

            const_iterator &operator=(const iterator &it) {
                this->i_node = it.i_node;
                return *this;
            };
        };

        iterator begin() { if (tree_size == 0) return iterator(end_node); else return iterator(begin_node); };

        const_iterator begin() const {
            if (tree_size == 0)
                return const_iterator(end_node);
            else
                return const_iterator(begin_node);
        };

        iterator end() { return iterator(end_node); };

        const_iterator end() const { return const_iterator(end_node); };

        bool empty() const {
            if (root->size == 0)
                return true;
            else
                return false;
        }

        size_type size() const { return tree_size; }

        size_type max_size() const { return size_type(-1); }

        ft::pair<iterator, bool> insert(const value_type &val) {
            node *i = find_node(root, val.first);
            if (i != NULL)
                return ft::make_pair(iterator(i), true);
            ft::pair<iterator, bool> pair = ft::make_pair(iterator(push_node(root, val)), true);
            return pair;
        }

        iterator insert(iterator position, const value_type &val) {
            (void) position;
            return insert(val).first;
        }

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last,
                    typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type * = 0) {
            for (; first != last; ++first)
                insert(*first);
        }

        void erase(iterator position) {
            erase(position->first);
            position.i_node = begin().i_node;
        }

        size_type erase(const key_type &k) {
            iterator f = find(k);
            if (tree_size == 0 || f == end())
                return 0;
            remove(root, k);
            return 1;
        }

        void erase(iterator first, iterator last) {
            for (; first != last; first++)
                erase(first);
        }

        void swap(map &x) {
            node *r = root;
            root = x.root;
            x.root = r;

            node *b = begin_node;
            begin_node = x.begin_node;
            x.begin_node = b;

            node *e = end_node;
            end_node = x.end_node;
            x.end_node = e;

            node *t = true_end_node;
            true_end_node = x.true_end_node;
            x.true_end_node = t;

            size_type s = tree_size;
            tree_size = x.tree_size;
            x.tree_size = s;

        }

        void clear() {
            erase(begin(), end());
        }

        key_compare key_comp() const { return comparator; }

        iterator find(const key_type &k) {
            return iterator(find_node(root, k));
        }

        const_iterator find(const key_type &k) const {
            return const_iterator(find_node(root, k));
        }

        size_type count(const key_type &k) const {
            if (find(k) != end())
                return 1;
            return 0;
        }

        iterator lower_bound(const key_type &k) {
            iterator it = begin();
            iterator end_it = end();
            for (; comparator(it->first, k) && it != end_it; it++);
            return it;
        };

        const_iterator lower_bound(const key_type &k) const {
            iterator it = begin();
            iterator end_it = end();
            for (; comparator(it->first, k) && it != end_it; it++);
            return it;
        };

        iterator upper_bound(const key_type &k) {
            iterator it = lower_bound(k);
            if (it->first != true_end_node->value->first && !comparator(k, it->first) && !comparator(it->first, k))
                return ++it;
            else
                return it;
        };

        const_iterator upper_bound(const key_type &k) const {
            const_iterator it = lower_bound(k);
            if (it->first != true_end_node->value->first && !comparator(k, it->first) && !comparator(it->first, k))
                return ++it;
            else
                return it;
        };

        ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        };

        ft::pair<iterator, iterator> equal_range(const key_type &k) {
            return ft::make_pair(lower_bound(k), upper_bound(k));
        };

        mapped_type &operator[](const key_type &k) { return insert(ft::make_pair(k, mapped_type())).first->second; };

        map &operator=(map x) {
            clear();
            insert(x.begin(), x.end());
            return *this;
        };

    private:

        node *find_node(node *cur_root, const key_type &k) {
            if (cur_root == NULL)
                return cur_root;
            if (k == cur_root->value->first)
                return cur_root;
            if (k < cur_root->value->first)
                return find_node(cur_root->left_node, k);
            else
                return find_node(cur_root->right_node, k);
        }

        node *rotate_right(node *n) {
            node *to_right = n->left_node;
            if (to_right == NULL)
                return (NULL);
            n->left_node = to_right->right_node;
            to_right->right_node = n;
            to_right->size = n->size;
            fix_size(n);
            return (to_right);
        }

        node *rotate_left(node *n) {
            node *to_left = n->right_node;
            if (to_left == NULL)
                return (NULL);
            n->right_node = to_left->left_node;
            to_left->left_node = n;
            to_left->size = n->size;
            fix_size(n);
            return (to_left);
        }

        node *push_to_root(node *n, const_reference val) {
            if (n == NULL) {
                node *new_n = create_node(val);
                if (begin_node == NULL || begin_node->value->first > new_n->value->first)
                    begin_node = new_n;
                if (true_end_node == NULL || true_end_node->value->first < new_n->value->first) {
                    true_end_node = new_n;
                    end_node->left_node = true_end_node;
                }
                if (n == root) {
                    root = new_n;
                    set_new_root(root);
                    end_node->root = root;
                }
                return new_n;
            }
            if (val.first < n->value->first) {
                n->left_node = push_to_root(n->left_node, val);
                node *new_n = rotate_right(n);
                if (n == root) {
                    root = new_n;
                    set_new_root(root);
                    end_node->root = root;
                }
                return new_n;
            }
            n->right_node = push_to_root(n->right_node, val);
            node *new_n = rotate_left(n);
            if (n == root) {
                root = new_n;
                set_new_root(root);
                end_node->root = root;
            }
            return new_n;
        }

        node *push_node(node *n, const_reference val) {
            if (n == NULL)
                return push_to_root(NULL, val);
            if ((unsigned long)rand() % (n->size + 1) == 0)
                return push_to_root(n, val);
            if (comparator(n->value->first, val.first))
                n->left_node = push_node(n->left_node, val);
            else
                n->right_node = push_node(n->right_node, val);
            fix_size(n);
            return (n);
        }

        node *join(node *n1, node *n2) {
            if (n1 == NULL)
                return (n2);
            if (n2 == NULL)
                return (n1);
            if ((unsigned  long)rand() % (n1->size + n2->size) < n1->size) {
                n1->right_node = join(n1->right_node, n2);
                fix_size(n1);
                return (n1);
            } else {
                n2->left_node = join(n1, n2->left_node);
                fix_size(n2);
                return (n2);
            }
        }

        node *remove(node *n, key_type key) {
            if (n == NULL)
                return n;
            if (n->value->first == key) {
                node *tmp = join(n->left_node, n->right_node);
                bool is_end_node = false;
                bool is_begin_node = false;
                if (n == root) {
                    root = tmp;
                    end_node->root = root;
                    if (root != NULL)
                        set_new_root(root);
                }
                if (n == true_end_node)
                    is_end_node = true;
                if (n == begin_node)
                    is_begin_node = true;
                delete_node(n);
                if (is_end_node)
                    true_end_node = search_end_node(root);
                if (is_begin_node)
                    begin_node = search_begin_node(root);
                return tmp;
            } else if (key < n->value->first)
                n->left_node = remove(n->left_node, key);
            else
                n->right_node = remove(n->right_node, key);
            return n;
        }

        node *create_node(const_reference val) {
            node *n = node_allocator.allocate(NODE_CREATION_SIZE);
            n->left_node = NULL;
            n->right_node = NULL;
            n->end_node = end_node;
            n->size = 0;
            n->root = root;
            n->is_end_node = false;
            n->value = alloc.allocate(1);
            alloc.construct(n->value, val);
            tree_size++;
            return n;
        }

        void delete_node(node *to_del) {
            alloc.destroy(to_del->value);
            alloc.deallocate(to_del->value, NODE_CREATION_SIZE);
            node_allocator.deallocate(to_del, NODE_CREATION_SIZE);
            tree_size--;
        }

        node *create_end_node() {
            node *n = node_allocator.allocate(NODE_CREATION_SIZE);
            n->left_node = NULL;
            n->right_node = NULL;
            n->end_node = NULL;
            n->size = 0;
            n->root = root;
            n->is_end_node = true;
            return n;
        }

        void set_new_root(node *cur_node) {
            if (cur_node->left_node != NULL)
                set_new_root(cur_node->left_node);
            if (cur_node->right_node != NULL)
                set_new_root(cur_node->right_node);
            cur_node->root = root;
        }

        size_type get_size(node *n) {
            if (n == NULL)
                return (0);
            return (n->size);
        }

        node *search_begin_node(node *cur) {
            node *min_left = NULL;
            node *min_right = NULL;
            if (cur == NULL)
                return NULL;
            if (cur->left_node != NULL)
                min_left = search_begin_node(cur->left_node);
            if (cur->right_node != NULL)
                min_right = search_begin_node(cur->right_node);
            if (min_left != NULL && (min_left->value->first < cur->value->first &&
                                     (min_right == NULL || min_left->value->first < min_right->value->first)))
                return min_left;
            if (min_right != NULL && (min_right->value->first < cur->value->first &&
                                      (min_left == NULL || min_right->value->first < min_left->value->first)))
                return min_left;
            return cur;
        }

        node *search_end_node(node *cur) {
            node *max_left = NULL;
            node *max_right = NULL;
            if (cur == NULL)
                return NULL;
            if (cur->left_node != NULL)
                max_left = search_end_node(cur->left_node);
            if (cur->right_node != NULL)
                max_right = search_end_node(cur->right_node);
            if (max_left != NULL && (max_left->value->first > cur->value->first &&
                                     (max_right == NULL || max_left->value->first > max_right->value->first)))
                return max_left;
            if (max_right != NULL && (max_right->value->first < cur->value->first &&
                                      (max_left == NULL || max_right->value->first > max_left->value->first)))
                return max_right;
            return cur;
        }

        void fix_size(node *n) {
            n->size = get_size(n->right_node) + get_size(n->left_node) + 1;
        }
    };

} // namespace ft
#endif